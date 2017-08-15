#include "footer.h"
#include <QPainter>

Footer::Footer(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    vlayout = new QVBoxLayout();
    hlayout = new QHBoxLayout();
    prevButton = new DImageButton(":/images/previous-normal.png", ":/images/previous-hover.png",":/images/previous-press.png");
    playButton = new DImageButton(":/images/play-normal.png", ":/images/play-hover.png",":/images/play-press.png");
    pauseButton = new DImageButton(":/images/pause-normal.png", ":/images/pause-hover.png",":/images/pause-press.png");
    nextButton = new DImageButton(":/images/next-normal.png", ":/images/next-hover.png",":/images/next-press.png");
    volumeButton = new DImageButton();
    slider = new QSlider(Qt::Horizontal);
    cover = new QLabel();
    display = new QLabel("");
    duration = new QLabel("00:00");;
    position = new QLabel("/00:00");;

    volumeButton->setNormalPic(":/images/volume-normal.png");
    cover->setPixmap(QPixmap(":/images/gedan_cover_default.png").scaled(50, 50));

    position->setVisible(false);
    duration->setVisible(false);
    display->setVisible(false);

    slider->setFixedHeight(7);

    hlayout->addWidget(position);
    hlayout->addWidget(duration);
    hlayout->addStretch();

    vlayout->addStretch();
    vlayout->addWidget(display);
    vlayout->addLayout(hlayout);
    vlayout->addStretch();

    layout->addWidget(cover);
    layout->addSpacing(10);
    layout->addLayout(vlayout);
    layout->addStretch();
    layout->addWidget(prevButton);
    layout->addSpacing(10);
    layout->addWidget(playButton);
    layout->addSpacing(10);
    layout->addWidget(nextButton);
    layout->addStretch();
    layout->addWidget(volumeButton);
    layout->addWidget(new QLabel("哈哈哈"));
    layout->addWidget(new QLabel("哈哈哈"));
    layout->addWidget(new QLabel("哈哈哈"));
    layout->addSpacing(10);

    setFixedHeight(70);
}

void Footer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#F6F6F6"));
    painter.drawRect(rect());

    //painter.setBrush(QColor("#E2E2E2"));
    //painter.drawRect(QRect(0, 0, rect().width(), 1));
}
