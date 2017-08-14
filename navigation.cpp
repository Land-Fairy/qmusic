#include "navigation.h"
#include <QButtonGroup>
#include <QToolButton>
#include <QDebug>
#include <QPainter>
#include <QLabel>

Navigation::Navigation(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    toolBar = new QToolBar();

    toolBar->setOrientation(Qt::Vertical);
    layout->setMargin(0);

    QStringList list;
    list << QStringLiteral("推荐") << QStringLiteral("电台") << QStringLiteral("排行") << QStringLiteral("本地歌曲") << QStringLiteral("播放历史");

    QButtonGroup *group = new QButtonGroup();

    for (int i=0; i<list.size(); ++i) {
        if (i == 0) {
            QLabel *label = new QLabel("在线音乐");
            label->setStyleSheet("QLabel {"
                                 "margin-top: 10px;"
                                 "margin-bottom: 5px;"
                                 "margin-left: 10px;"
                                 "color: #A9A9A9;"
                                 "}");
            toolBar->addWidget(label);
            toolBar->addSeparator();
        }

        if (i == 3) {
            QLabel *label = new QLabel("我的音乐");
            label->setStyleSheet("QLabel {"
                                 "margin-top: 20px;"
                                 "margin-bottom: 0px;"
                                 "margin-left: 10px;"
                                 "color: #A9A9A9;"
                                 "}");
            toolBar->addWidget(label);
            toolBar->addSeparator();
        }

        QToolButton *btn = new QToolButton();
        btn->setText(list.at(i));
        btn->setFixedHeight(40);
        btn->setFixedWidth(200);
        btn->setCheckable(true);
        group->addButton(btn);
        toolBar->addWidget(btn);

        if (i == 0)
            btn->setChecked(true);
    }

    layout->addWidget(toolBar);
    setFixedWidth(200);

    connect(group, SIGNAL(buttonClicked(int)), this, SLOT(buttonClicked(int)));
}

void Navigation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#F9F9F9"));
    painter.drawRect(rect());
}

void Navigation::buttonClicked(int index)
{
    qDebug() << index;
}
