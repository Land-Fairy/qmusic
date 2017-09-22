#include "interface.h"
#include <QPainter>

InterFace::InterFace(QWidget *parent)
    : QWidget(parent)
{
    layout = new QStackedLayout(this);
    searchPage = new SearchPage();
    listPage = new QListWidget();

    layout->addWidget(searchPage);
    layout->addWidget(listPage);

    layout->setCurrentIndex(0);
}

void InterFace::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#FFFFFF"));
    painter.drawRect(rect());
}
