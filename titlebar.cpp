#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent)
{
    layout = new QHBoxLayout(this);
    searchEdit = new QLineEdit();

    layout->addStretch();
    layout->addWidget(searchEdit);
}
