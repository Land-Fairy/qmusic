#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QStackedLayout>
#include "./widgets/search_page.h"

class InterFace : public QWidget
{
    Q_OBJECT

public:
    InterFace(QWidget *parent = 0);

    SearchPage *searchPage;

protected:
    void paintEvent(QPaintEvent *);

private:
    QStackedLayout *layout;
};

#endif // INTERFACE_H
