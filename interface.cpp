#include "interface.h"
#include <QPainter>

InterFace::InterFace(QWidget *parent)
    : QWidget(parent)
{
    layout = new QStackedLayout(this);
    searchPage = new SearchPage();

    layout->addWidget(searchPage);
}

void InterFace::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#EDEDED"));
    painter.drawRect(rect());
}
