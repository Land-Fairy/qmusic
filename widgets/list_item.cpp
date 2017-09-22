#include "list_item.h"
#include <QHBoxLayout>
#include <QLabel>

ListItem::ListItem(int num, const QString &name, const QString &artist, QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);

    auto number = new QLabel;
    number->setText(QString::number(num));

    auto nameLabel = new QLabel;
    nameLabel->setText(name);

    auto artistLabel = new QLabel;
    artistLabel->setText(artist);

    layout->addWidget(number);
    layout->addWidget(nameLabel);
    layout->addWidget(artistLabel);
}
