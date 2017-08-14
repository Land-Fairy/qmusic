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
    slider = new QSlider(Qt::Horizontal);
    display = new QLabel("");
    duration = new QLabel("00:00");;
    position = new QLabel("00:00");;

    slider->setFixedWidth(parentWidget()->width());
    slider->setFixedHeight(6);

    hlayout->addWidget(display);
    hlayout->addStretch();
    hlayout->addWidget(position);
    hlayout->addWidget(new QLabel("/"));
    hlayout->addWidget(duration);

    vlayout->addStretch();
    vlayout->addLayout(hlayout);
    vlayout->addSpacing(5);
    vlayout->addWidget(slider);
    vlayout->addStretch();

    layout->addSpacing(20);
    layout->addWidget(prevButton);
    layout->addSpacing(10);
    layout->addWidget(playButton);
    layout->addSpacing(10);
    layout->addWidget(nextButton);
    layout->addStretch();
    layout->addLayout(vlayout);
    layout->addStretch();

    setFixedHeight(parentWidget()->height() / 4 - 45);
}

void Footer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#FFFFFF"));
    painter.drawRect(rect());

    painter.setBrush(QColor("#E2E2E2"));
    painter.drawRect(QRect(0, 0, rect().width(), 1));
}
