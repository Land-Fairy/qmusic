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

protected:
    void paintEvent(QPaintEvent *);

private:
    QVBoxLayout *layout;
    QToolBar *toolBar;

private slots:
    void buttonClicked(int index);

signals:
    void indexChanged(int current);
};

#endif // NAVIGATION_H
