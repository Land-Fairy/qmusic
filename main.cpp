#include <DApplication>
#include <DWidgetUtil>
#include <QDesktopWidget>
#include "main_window.h"
#include "utils.h"

#include <QDebug>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "1.35");

    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);

    app.setTheme("light");

    const QString acknowledgementLink = "https://github.com/rekols";

    if (app.setSingleInstance("qq-music")) {
        app.setApplicationVersion("0.1");
        app.setProductName("QQ音乐");
        app.setProductIcon(QPixmap::fromImage(QImage(":/images/logo.png")));
        app.setApplicationDescription(DApplication::translate("MainWindow", "本项目代码不用于商用，仅限研究和学习使用.") + "\n");
        app.setApplicationAcknowledgementPage(acknowledgementLink);
        app.setWindowIcon(QIcon(":/images/logo.png"));

        MainWindow w;
        w.show();
        w.setWindowTitle("QQ音乐");
        w.setFixedSize(800, 500);

        Dtk::Widget::moveToCenter(&w);

        qApp->setStyleSheet(Utils::getQssContent(":/qss/style.qss"));

        return app.exec();
    }

    return 0;
}
