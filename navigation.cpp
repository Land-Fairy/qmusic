#include "navigation.h"
#include <QButtonGroup>
#include <QToolButton>
#include <QDebug>
#include <QPainter>

Navigation::Navigation(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    toolBar = new QToolBar();

    toolBar->setOrientation(Qt::Vertical);

    QStringList list;
    list << QStringLiteral("首页") << QStringLiteral("排行") << QStringLiteral("本地歌曲");

    QButtonGroup *group = new QButtonGroup();

    for (int i=0; i<list.size(); ++i) {
        QToolButton *btn = new QToolButton();
        btn->setText(list.at(i));
        btn->setFixedHeight(40);
        btn->setCheckable(true);
        group->addButton(btn);
        toolBar->addWidget(btn);

        if (i == 0)
            btn->setChecked(true);
    }

    layout->addWidget(toolBar);

    connect(group, SIGNAL(buttonClicked(int)), this, SLOT(buttonClicked(int)));
}

void Navigation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#EFEFEF"));
    painter.drawRect(rect());
}

void Navigation::buttonClicked(int index)
{
    qDebug() << index;
}
