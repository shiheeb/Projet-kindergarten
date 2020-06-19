#ifndef STATISITIQUE_CLUB_H
#define STATISITIQUE_CLUB_H

#include <QWidget>

namespace Ui {
class statisitique_club;
}

class statisitique_club : public QWidget
{
    Q_OBJECT

public:
    explicit statisitique_club(QWidget *parent = nullptr);
    ~statisitique_club();

private:
    Ui::statisitique_club *ui;
};

#endif // STATISITIQUE_CLUB_H
