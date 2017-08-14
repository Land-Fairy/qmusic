#include "main_window.h"
#include <dtitlebar.h>
#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QVBoxLayout();
    hlayout = new QHBoxLayout();
    navigation = new Navigation(this);
    interFace = new InterFace();
    footer = new Footer(this);
    tb = new TitleBar();
    api = new QQMusicAPI();
    player = new Player();

    if (titlebar()) {
        tb->searchEdit->setFixedWidth(width() / 2);
        titlebar()->setCustomWidget(tb, Qt::AlignHCenter, false);
        titlebar()->setSeparatorVisible(true);
    }

    hlayout->addWidget(navigation);
    hlayout->addWidget(interFace);

    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addLayout(hlayout);
    layout->addWidget(footer);

    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);

    /* search event*/
    connect(tb->searchEdit, &QLineEdit::returnPressed, this, [=]{
        interFace->searchPage->list->clear();
        api->search(tb->searchEdit->text(), 1);

        if (!names.isEmpty())
            names.clear();
        if (!songUrls.isEmpty())
            songUrls.clear();
        if (!imageUrls.isEmpty())
            imageUrls.clear();
    });

    connect(api, &QQMusicAPI::searchList, this, [=](QString name, QString url, QString image_url){
        interFace->searchPage->list->addItem(name);

        names << name;
        songUrls << url;
        imageUrls << image_url;
    });

    connect(interFace->searchPage->list, &QListWidget::doubleClicked, this, [=]{
        player->setMedia(QUrl(songUrls.at(interFace->searchPage->list->currentRow())));
        //player->play();
    });

    /* MediaPlay event*/
    connect(player, &Player::durationChanged, this, [=](qint64 duration) {
        QTime time(0, 0, 0);
        time = time.addMSecs(duration);

        footer->slider->setRange(0, duration);
        footer->duration->setText("/ " + time.toString("mm:ss"));
    });

    connect(player, &Player::positionChanged, this, [=](qint64 position) {
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

    connect(player, &Player::stateChanged, this, [=](QMediaPlayer::State status) {
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

    connect(player, &Player::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
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

            footer->display->setText(names.at(interFace->searchPage->list->currentRow()));
        }
        qDebug() << status;
    });

    /* footer slider event*/
    connect(footer->slider, &QSlider::sliderMoved, this, [=] {
        player->setPosition(footer->slider->value());
    });
    connect(footer->slider, &QSlider::sliderPressed, this, [=] {
        player->setPosition(footer->slider->value());
    });
}
