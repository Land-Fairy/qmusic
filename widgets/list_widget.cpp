#include "list_widget.h"
#include <QVBoxLayout>
#include <QStringListModel>
#include "list_item.h"

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QVBoxLayout(this);
    listView = new QListView;
    model = new QStringListModel;

    listView->setModel(model);

    layout->addWidget(listView);
}

void ListWidget::addMusic(const QString &name, const QString &artist)
{
    model->insertRows(model->rowCount(), 1);
    auto index = model->index(model->rowCount() - 1);
    listView->setIndexWidget(index, new ListItem(model->rowCount(), name, artist));
}
