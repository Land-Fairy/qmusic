#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QStackedLayout>
#include <QListWidget>
#include "./widgets/search_page.h"

class InterFace : public QWidget
{
    Q_OBJECT

public:
    InterFace(QWidget *parent = 0);

    QStackedLayout *layout;
    SearchPage *searchPage;
    QListWidget *listPage;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // INTERFACE_H
