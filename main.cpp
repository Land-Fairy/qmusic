#include <DApplication>
#include <DWidgetUtil>
#include <QDesktopWidget>
#include "main_window.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);
    app.setTheme("light");

    MainWindow w;
    w.show();

    w.setMinimumSize(qApp->desktop()->width() / 1.5, qApp->desktop()->height() / 1.4);

    Dtk::Widget::moveToCenter(&w);

    return app.exec();
}
