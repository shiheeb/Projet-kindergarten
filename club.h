#ifndef CLUB_H
#define CLUB_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class club
{
    public:
    club();

    club(QString,QString,QString,QString,QString);
    QString get_id();
    QString get_nom();
    QString get_enca();
    QString get_datee();

    bool ajouter_c();
    QString get_numtt();

    QSqlQueryModel * afficher_c ();
    bool supprimer_c (int);
     bool modifier_c(club);
     QSqlQueryModel * rechercher_c(QSqlQuery );
     bool verif_idc(QString ch_id);
     bool verif_nom(QString nom);
     QSqlQueryModel * afficher_clublist();
private :
    QString id ;
    QString nom ;
     QString datee;
    QString enca;
    QString numtt;
};

#endif // CLUB_H
