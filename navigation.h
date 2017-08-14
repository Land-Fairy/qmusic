#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QToolBar>

class Navigation : public QWidget
{
    Q_OBJECT

public:
    Navigation(QWidget *parent = 0);

private:
    QVBoxLayout *layout;
    QToolBar *toolBar;
};

#endif // NAVIGATION_H
