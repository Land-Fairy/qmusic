#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget;
    layout = new QVBoxLayout;

    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);
}
