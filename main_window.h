#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QVBoxLayout>
#include "navigation.h"
#include "interface.h"
#include "footer.h"
#include "titlebar.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QWidget *mainWidget;
    QVBoxLayout *layout;
    QHBoxLayout *hlayout;
    Navigation *navigation;
    InterFace *interFace;
    Footer *footer;
    TitleBar *tb;
};

#endif
