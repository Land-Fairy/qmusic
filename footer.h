#ifndef FOOTER_H
#define FOOTER_H

#include <QWidget>
#include <QHBoxLayout>
#include <dimagebutton.h>
#include <QSlider>
#include <QLabel>

DWIDGET_USE_NAMESPACE

class Footer : public QWidget
{
    Q_OBJECT

public:
    Footer(QWidget *parent = 0);

    QLabel *display;
    QLabel *duration;
    QLabel *position;
    QLabel *cover;
    QSlider *slider;

    DImageButton *prevButton;
    DImageButton *playButton;
    DImageButton *pauseButton;
    DImageButton *nextButton;

protected:
    void paintEvent(QPaintEvent *);

private:
    QHBoxLayout *layout;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
};

#endif // FOOTER_H
