#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>

class SearchPage : public QWidget
{
    Q_OBJECT

public:
    explicit SearchPage(QWidget *parent = 0);

    QListWidget *list;

private:
    QVBoxLayout *layout;
};

#endif // SEARCHPAGE_H
