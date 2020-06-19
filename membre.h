#ifndef MEMBRE_H
#define MEMBRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class member
{
    public:
    member();

    member(QString,QString,QString,QString,QString);
    QString get_id();
    QString get_nom();
    QString get_nc();
    QString get_nbsc();
    bool verif_email(QString );

    bool ajouter_m();
    QString get_membr();
QString get_mail();
    QSqlQueryModel * afficher_m ();
    bool supprimer_m (int);
     bool modifier_m(member);
     QSqlQueryModel * rechercher_m(QSqlQuery );
     bool verif_idm(QString ch_id);
     bool verif_nom(QString nom);
     QSqlQueryModel * afficher_memberlist();
private :
    QString id ;
    QString nom ;
     QString nc;
QString mail;
    QString nbsc;
};





#endif // MEMBRE_H
