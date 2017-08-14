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

private slots:
    void buttonClicked(int index);
};

#endif // NAVIGATION_H
