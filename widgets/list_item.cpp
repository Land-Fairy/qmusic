#include "list_item.h"
#include <QHBoxLayout>
#include <QLabel>

ListItem::ListItem(const QString &name, const QString &artist, QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);

    auto nameLabel = new QLabel;
    nameLabel->setText(name);

    auto artistLabel = new QLabel;
    artistLabel->setText(artist);

    layout->addWidget(nameLabel);
    layout->addStretch();
    layout->addWidget(artistLabel);
}
