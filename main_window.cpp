#include "main_window.h"
#include <dtitlebar.h>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QVBoxLayout();
    hlayout = new QHBoxLayout();
    navigation = new Navigation(this);
    interFace = new InterFace();
    footer = new Footer(this);
    tb = new TitleBar();
    api = new QQMusicAPI();

    if (titlebar()) {
        tb->searchEdit->setFixedWidth(width() / 2);
        titlebar()->setCustomWidget(tb, Qt::AlignHCenter, false);
        titlebar()->setSeparatorVisible(true);
    }

    hlayout->addWidget(navigation);
    hlayout->addWidget(interFace);

    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addLayout(hlayout);
    layout->addWidget(footer);

    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);

    connect(tb->searchEdit, &QLineEdit::returnPressed, this, [=]{
        interFace->searchPage->list->clear();
        api->search(tb->searchEdit->text(), 1);

        if (!names.isEmpty())
            names.clear();
        if (!songUrls.isEmpty())
            songUrls.clear();
        if (!imageUrls.isEmpty())
            imageUrls.clear();
    });

    connect(api, &QQMusicAPI::searchList, this, [=](QString name, QString url, QString image_url){
        interFace->searchPage->list->addItem(name);

        names << name;
        songUrls << url;
        imageUrls << image_url;
    });
}
