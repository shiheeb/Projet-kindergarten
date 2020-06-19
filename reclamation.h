#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation
{  public:
    Reclamation() ;
    Reclamation(QString ,QString ,QString,QString,QString);
    QString get_num( ){return num ;}

    QString get_eleve(){ return  eleve;}
    QString get_parent() {return parent ;}
    QString get_objet(){return  objet ;}
     QString get_prof(){return  prof ;}
    void setnum(QString);
    void seteleve(QString);
    void setparent(int);
    void setobjet(int);
 QSqlQueryModel * getIdModel();
    bool ajouter(Reclamation r);
    bool modifier (Reclamation r);
    bool supprimer(QString numm);
    QSqlQueryModel * afficher();
    QSqlQueryModel *rechercher_num(QString);
     QSqlQueryModel *rechercher_eleve(QSqlQuery);
    QSqlQueryModel *tri_num();
    QSqlQueryModel *tri_nom();
    bool verif_num(QString num);
    bool verif_eleve(QString eleve);
    bool verif_parent(QString parent);

    bool verif_prof(QString prof);

    private:
    QString num,eleve,parent, objet, prof ;


};

#endif // RECLAMATION_H

