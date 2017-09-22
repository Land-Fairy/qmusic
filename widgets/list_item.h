#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include <QWidget>

class ListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListItem(const QString &name, const QString &artist, QWidget *parent = nullptr);
};

#endif // LIST_ITEM_H
