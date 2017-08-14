#include "footer.h"
#include <QPainter>

Footer::Footer(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);

    prevButton = new DImageButton(":/images/previous-normal.png", ":/images/previous-hover.png",":/images/previous-press.png");
    playButton = new DImageButton(":/images/play-normal.png", ":/images/play-hover.png",":/images/play-press.png");
    pauseButton = new DImageButton(":/images/pause-normal.png", ":/images/pause-hover.png",":/images/pause-press.png");
    nextButton = new DImageButton(":/images/next-normal.png", ":/images/next-hover.png",":/images/next-press.png");
    slider = new QSlider(Qt::Horizontal);

    slider->setFixedWidth(parentWidget()->width());
    slider->setFixedHeight(7);

    layout->addSpacing(20);
    layout->addWidget(prevButton);
    layout->addSpacing(10);
    layout->addWidget(playButton);
    layout->addSpacing(10);
    layout->addWidget(nextButton);
    layout->addStretch();
    layout->addWidget(slider);
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
