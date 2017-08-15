#include "titlebar.h"
#include <QLabel>
#include <QFontMetrics>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    searchEdit = new QLineEdit();

    QLabel *logo = new QLabel();
    logo->setPixmap(QPixmap(":/images/logo.png").scaled(20, 20));

    layout->setContentsMargins(0, 0, 0, 0);

    layout->addSpacing(10);
    layout->addWidget(logo);
    layout->addSpacing(parentWidget()->width() / 3.5 - 40);
    layout->addStretch();
    layout->addWidget(searchEdit);

    searchEdit->setFixedHeight(25);
    searchEdit->setFixedWidth(280);
}
