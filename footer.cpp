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
    duration = new QLabel(" / 00:00");;
    position = new QLabel("00:00");;

    display->setVisible(false);
    duration->setVisible(false);
    position->setVisible(false);

    display->setStyleSheet("QLabel { color: #353535; }");
    duration->setStyleSheet("QLabel { color: #353535; }");
    position->setStyleSheet("QLabel { color: #353535; }");

    volumeButton->setNormalPic(":/images/volume-normal.png");
    cover->setPixmap(QPixmap(":/images/gedan_cover_default.png").scaled(50, 50));

    slider->setFixedHeight(4);

    hlayout->setContentsMargins(0, 0, 0, 0);
    hlayout->addWidget(position);
    hlayout->addWidget(duration);
    hlayout->addStretch();

    vlayout->addStretch();
    vlayout->addWidget(display);
    vlayout->addLayout(hlayout);
    vlayout->addStretch();

    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addSpacing(10);
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
    layout->addSpacing(30);

    setFixedHeight(65);
}

void Footer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#FFFFFF"));
    painter.drawRect(rect());

    painter.setBrush(QColor("#EAEAEA"));
    painter.drawRect(QRect(0, 0, rect().width(), 1));
}
