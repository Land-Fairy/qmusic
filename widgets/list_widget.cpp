#include "list_widget.h"
#include <QVBoxLayout>

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QVBoxLayout(this);
    listView = new QListView;
    model = new QStringListModel;

    listView->setModel(model);

    layout->addWidget(listView);
}
