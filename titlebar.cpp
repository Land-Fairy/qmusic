#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent)
{
    layout = new QHBoxLayout(this);
    searchEdit = new QLineEdit();

    layout->setContentsMargins(0, 0, 0, 0);

    layout->addStretch();
    layout->addWidget(searchEdit);

    searchEdit->setFixedHeight(25);
}
