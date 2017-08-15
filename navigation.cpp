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

    setFixedWidth(parentWidget()->width() / 3.5);

    toolBar->setOrientation(Qt::Vertical);
    layout->setMargin(0);
    layout->setSpacing(0);

    QStringList list;
    list << QStringLiteral("音乐库");
    list << QStringLiteral("播放列表");

    QLabel *loginLogo = new QLabel();
    loginLogo->setPixmap(QPixmap(":/images/login.png").scaled(70, 70));
    loginLogo->setFixedSize(70, 70);
    QLabel *loginLabel = new QLabel("登录");
    loginLabel->setFixedHeight(20);

    layout->addSpacing(20);
    layout->addWidget(loginLogo, 0, Qt::AlignHCenter);
    layout->addSpacing(10);
    layout->addWidget(loginLabel, 0, Qt::AlignHCenter);
    layout->addSpacing(20);
    layout->addWidget(toolBar);

    QButtonGroup *group = new QButtonGroup();

    for (int i=0; i<list.size(); ++i) {
        if (i == 0) {
            QLabel *label = new QLabel("在线音乐");
            label->setStyleSheet("QLabel {"
                                 "margin-top: 10px;"
                                 "margin-bottom: 5px;"
                                 "margin-left: 15px;"
                                 "color: #A9A9A9;"
                                 "}");
            toolBar->addWidget(label);
        }

        if (i == 1) {
            QLabel *label = new QLabel("我的音乐");
            label->setStyleSheet("QLabel {"
                                 "margin-top: 20px;"
                                 "margin-bottom: 5px;"
                                 "margin-left: 15px;"
                                 "color: #A9A9A9;"
                                 "}");
            toolBar->addWidget(label);
        }

        QToolButton *btn = new QToolButton();
        btn->setText(list.at(i));
        btn->setFixedHeight(30);
        btn->setFixedWidth(width());
        btn->setCheckable(true);
        group->addButton(btn);
        toolBar->addWidget(btn);

        if (i == 0)
            btn->setChecked(true);
    }

    connect(group, SIGNAL(buttonClicked(int)), this, SLOT(buttonClicked(int)));
}

void Navigation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#F9F9F9"));
    painter.drawRect(rect());

    painter.setBrush(QColor("#EFEFEF"));
    painter.drawRect(QRect(width() - 1, 0, 1, height()));
}

void Navigation::buttonClicked(int index)
{
    qDebug() << index;

    switch (index) {
    case -2:
        qDebug() << "推荐";
        break;
    case -3:
        qDebug() << "电台";
        break;
    case -4:
        qDebug() << "排行";
        break;
    case -5:
        qDebug() << "本地歌曲";
        break;
    case -6:
        qDebug() << "历史播放";
        break;
    }
}
