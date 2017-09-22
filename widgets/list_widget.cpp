#include "list_widget.h"
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "list_item.h"

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QVBoxLayout(this);
    listWidget = new QListWidget;

    layout->addWidget(listWidget);
}

void ListWidget::addMusic(const QString &title, const QString &artist)
{
    QListWidgetItem *itemWidget = new QListWidgetItem(listWidget);
    ListItem *item = new ListItem(title, artist);

    itemWidget->setSizeHint(item->sizeHint());
    listWidget->setItemWidget(itemWidget, item);
}
