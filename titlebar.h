#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    TitleBar(QWidget *parent = 0);

    QLineEdit *searchEdit;

};

#endif // TITLEBAR_H
