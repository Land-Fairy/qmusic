#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QVBoxLayout();
    hlayout = new QHBoxLayout();
    navigation = new Navigation();
    interFace = new InterFace();

    hlayout->addWidget(navigation);
    hlayout->addWidget(interFace);

    layout->addLayout(hlayout);

    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);
}
