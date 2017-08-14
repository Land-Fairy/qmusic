#include "navigation.h"
#include <QButtonGroup>
#include <QToolButton>

Navigation::Navigation(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    toolBar = new QToolBar();

    toolBar->setOrientation(Qt::Vertical);

    QStringList list;
    list << QStringLiteral("首页");
    list << QStringLiteral("排行");
    list << QStringLiteral("本地歌曲");

    QButtonGroup *group = new QButtonGroup();

    for (int i=0; i<list.size(); ++i) {
        QToolButton *btn = new QToolButton();
        btn->setText(list.at(i));
        btn->setFixedHeight(40);
        btn->setCheckable(true);
        group->addButton(btn);
        toolBar->addWidget(btn);

        if (i == 1)
            btn->setChecked(true);
    }

    layout->addWidget(toolBar);
}
