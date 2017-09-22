#ifndef LIST_WIDGET_H
#define LIST_WIDGET_H

#include <QWidget>
#include <QListWidget>

class ListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ListWidget(QWidget *parent = nullptr);

    void addMusic(const QString &title, const QString &artist);

private:
    QListWidget *listWidget;
};

#endif // LIST_WIDGET_H
