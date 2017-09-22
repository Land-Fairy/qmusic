#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "list_widget.h"

class SearchPage : public QWidget
{
    Q_OBJECT

public:
    explicit SearchPage(QWidget *parent = 0);

    ListWidget *list;

private:
    QVBoxLayout *layout;
};

#endif // SEARCHPAGE_H
