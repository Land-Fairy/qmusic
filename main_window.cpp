#include "main_window.h"
#include <dtitlebar.h>
#include <QTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QVBoxLayout();
    hlayout = new QHBoxLayout();
    navigation = new Navigation(this);
    interFace = new InterFace();
    footer = new Footer(this);
    tb = new TitleBar(this);
    api = new QQMusicAPI(this);
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist();
    http = new QNetworkAccessManager(this);

    player->setPlaylist(playlist);

    if (titlebar()) {
        tb->searchEdit->setFixedWidth(width() / 3 + width() / 3);
        titlebar()->setCustomWidget(tb, Qt::AlignHCenter, false);
        titlebar()->setSeparatorVisible(true);
        titlebar()->setWindowFlags(titlebar()->windowFlags() &~ Qt::WindowMaximizeButtonHint);
    }

    hlayout->addWidget(navigation);
    hlayout->addWidget(interFace);

    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addLayout(hlayout);
    layout->addWidget(footer);

    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);

    connect(navigation, &Navigation::indexChanged, this, [=](int current){
        interFace->layout->setCurrentIndex(current);
    });

    /* search event*/
    connect(tb->searchEdit, &DSearchEdit::returnPressed, this, [=]{
        if (tb->searchEdit->text().isEmpty())
            return;

        names.clear();
        songUrls.clear();
        imageUrls.clear();
        playlist->clear();

        interFace->searchPage->list->clear();
        api->search(tb->searchEdit->text(), 1);
    });

    connect(api, &QQMusicAPI::searchList, this, [=](QString name, QString url, QString image_url){
        names << name;
        songUrls << url;
        imageUrls << image_url;
        playlist->addMedia(QUrl(url));

        interFace->searchPage->list->addItem(name);
    });

    connect(interFace->searchPage->list, &QListWidget::doubleClicked, this, [=]{
        int current = interFace->searchPage->list->currentRow();

        footer->cover->setPixmap(QPixmap(":/images/gedan_cover_default.png").scaled(50, 50));

        QEventLoop loop;
        QUrl url = imageUrls.at(current);
        QNetworkRequest request(url);
        QNetworkReply *reply = http->get(request);
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        footer->cover->setPixmap(pixmap.scaled(50, 50));

        playlist->setCurrentIndex(current);
    });

    /* MediaPlay event*/
    connect(player, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
        QTime time(0, 0, 0);
        time = time.addMSecs(duration);

        footer->slider->setRange(0, duration);
        footer->duration->setText("/ " + time.toString("mm:ss"));
    });

    connect(player, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
        QTime time(0, 0, 0);
        time = time.addMSecs(position);

        footer->slider->setValue(position);
        footer->position->setText(time.toString("mm:ss"));
    });

    connect(footer->playButton, &DImageButton::clicked, this, [=] {
        if (player->state() == QMediaPlayer::PlayingState)
            player->pause();
        else
            player->play();
    });

    connect(player, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State status) {
        if (status == QMediaPlayer::PlayingState) {
            footer->playButton->setNormalPic(":/images/pause-normal.png");
            footer->playButton->setHoverPic(":/images/pause-hover.png");
            footer->playButton->setPressPic(":/images/pause-press.png");
        } else {
            footer->playButton->setNormalPic(":/images/play-normal.png");
            footer->playButton->setHoverPic(":/images/play-hover.png");
            footer->playButton->setPressPic(":/images/play-press.png");
        }
    });

    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadingMedia) {
            footer->display->setVisible(true);
            footer->position->setVisible(false);
            footer->duration->setVisible(false);
            footer->display->setText("加载中...");
        }
        if (status == QMediaPlayer::EndOfMedia) {
            footer->slider->setValue(0);
            footer->position->setVisible(false);
            footer->duration->setVisible(false);
            footer->display->setVisible(false);
        }
        if (status == QMediaPlayer::LoadedMedia) {
            player->play();
        }
        if (status == QMediaPlayer::BufferedMedia) {
            footer->position->setVisible(true);
            footer->duration->setVisible(true);
            footer->display->setVisible(true);

            footer->display->setText(names.at(playlist->currentIndex()));
        }
    });

    /* footer slider event*/
    connect(footer->slider, &QSlider::sliderMoved, this, [=] {
        //player->setPosition(footer->slider->value());
    });
    connect(footer->slider, &QSlider::sliderPressed, this, [=] {
        player->setPosition(footer->slider->value());
    });

    /* footer button event */
    connect(footer->prevButton, &DImageButton::clicked, this, [=] {
        playlist->previous();
    });
    connect(footer->nextButton, &DImageButton::clicked, this, [=] {
        playlist->next();
    });
}
