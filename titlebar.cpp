#include "titlebar.h"
#include <QLineEdit>

TitleBar::TitleBar(QWidget *parent)
{
    layout = new QHBoxLayout(this);

    QLineEdit *searchEdit = new QLineEdit();

    layout->addStretch();
    layout->addStretch();
    layout->addWidget(searchEdit);
    layout->addStretch();
}
