#include "titlebar.h"
#include <QLabel>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    searchEdit = new DSearchEdit();

    searchEdit->setPlaceHolder("搜索");

    QLabel *logo = new QLabel();
    logo->setPixmap(QPixmap(":/images/logo.png").scaled(20, 20));

    layout->setContentsMargins(0, 0, 0, 0);

    layout->addSpacing(10);
    layout->addWidget(logo);
    layout->addSpacing(parentWidget()->width() / 3.5 - 40);
    layout->addStretch();
    layout->addWidget(searchEdit);
    layout->addSpacing(20);

    searchEdit->setFixedHeight(25);
}
