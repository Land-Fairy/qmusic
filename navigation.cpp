#include "navigation.h"
#include <QButtonGroup>
#include <QDebug>
#include <QPainter>
#include <QLabel>

Navigation::Navigation(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    toolBar = new QToolBar();
    btn1 = new QToolButton();
    btn2 = new QToolButton();

    setFixedWidth(parentWidget()->width() / 3.5);

    toolBar->setOrientation(Qt::Vertical);
    layout->setMargin(0);
    layout->setSpacing(0);

    QLabel *loginLogo = new QLabel();
    loginLogo->setPixmap(QPixmap(":/images/login.png").scaled(70, 70));
    loginLogo->setFixedSize(70, 70);
    QLabel *loginLabel = new QLabel("登录");
    loginLabel->setFixedHeight(20);

    //layout->addSpacing(20);
    //layout->addWidget(loginLogo, 0, Qt::AlignHCenter);
    //layout->addSpacing(10);
    //layout->addWidget(loginLabel, 0, Qt::AlignHCenter);
    //layout->addSpacing(20);
    layout->addWidget(toolBar);

    QButtonGroup *group = new QButtonGroup();

    QLabel *label = new QLabel("在线音乐");
    label->setStyleSheet("QLabel {"
                         "margin-top: 10px;"
                         "margin-bottom: 5px;"
                         "margin-left: 15px;"
                         "color: #A9A9A9;"
                         "}");
    toolBar->addWidget(label);

    btn1->setText("搜索");
    btn1->setFixedHeight(30);
    btn1->setFixedWidth(width());
    btn1->setCheckable(true);
    group->addButton(btn1);
    toolBar->addWidget(btn1);


    QLabel *label2 = new QLabel("我的音乐");
    label2->setStyleSheet("QLabel {"
                         "margin-top: 20px;"
                         "margin-bottom: 5px;"
                         "margin-left: 15px;"
                         "color: #A9A9A9;"
                         "}");
    toolBar->addWidget(label2);

    btn2->setText("播放列表");
    btn2->setFixedHeight(30);
    btn2->setFixedWidth(width());
    btn2->setCheckable(true);
    group->addButton(btn2);
    toolBar->addWidget(btn2);

    btn1->setChecked(true);

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
    switch (index) {
    case -2:
        indexChanged(0);
        break;
    case -3:
        indexChanged(1);
        break;
    }
}
