#ifndef FOOTER_H
#define FOOTER_H

#include <QWidget>
#include <QHBoxLayout>

class Footer : public QWidget
{
    Q_OBJECT

public:
    Footer(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    QHBoxLayout *layout;
};

#endif // FOOTER_H
