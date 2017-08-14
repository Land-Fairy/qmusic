#include "main_window.h"
#include <dtitlebar.h>
#include <QTime>

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
        player->play();

        footer->display->setText(names.at(interFace->searchPage->list->currentRow()));
    });

    /* MediaPlay event*/
    connect(player, &Player::durationChanged, this, [=](qint64 duration) {
        QTime time(0, 0, 0);
        time = time.addMSecs(duration);

        footer->slider->setRange(0, duration);
        footer->duration->setText(time.toString("mm:ss"));
    });

    connect(player, &Player::positionChanged, this, [=](qint64 position) {
        QTime time(0, 0, 0);
        time = time.addMSecs(position);

        footer->slider->setValue(position);
        footer->position->setText(time.toString("mm:ss"));
    });

    /* footer slider event*/
    connect(footer->slider, &QSlider::sliderMoved, this, [=] {
        player->setPosition(footer->slider->value());
    });
    connect(footer->slider, &QSlider::sliderPressed, this, [=] {
        player->setPosition(footer->slider->value());
    });
}
