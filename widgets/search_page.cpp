#include "./widgets/search_page.h"

SearchPage::SearchPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    list = new ListWidget();

    layout->addWidget(list);
}
