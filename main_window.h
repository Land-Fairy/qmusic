#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "navigation.h"
#include "interface.h"
#include "footer.h"
#include "titlebar.h"
#include "./api/qqmusic_api.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QWidget *mainWidget;
    QVBoxLayout *layout;
    QHBoxLayout *hlayout;
    Navigation *navigation;
    InterFace *interFace;
    Footer *footer;
    TitleBar *tb;

    QQMusicAPI *api;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;

    QStringList names;
    QStringList songUrls;
    QStringList imageUrls;
};

#endif
