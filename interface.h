#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QVBoxLayout>

class InterFace : public QWidget
{
    Q_OBJECT

public:
    InterFace(QWidget *parent = 0);

private:
    QVBoxLayout *layout;
};

#endif // INTERFACE_H
