#ifndef PARENT_H
#define PARENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Parent
{  public:
    Parent() ;
    Parent(QString ,QString ,QString,QString,QString, QString);
    QString get_CIN( ){return CIN ;}
    QString get_num() {return numero ;}
    QString get_nom(){ return  nom;}
    QString get_prenom() {return prenom ;}
    QString get_email(){return  email ;}
    QString get_nomeleve(){return  nomeleve ;}
    void setNom(QString);
    void setPrenom(QString);
    void setCIN(QString);
    void setNum(QString);
    void setEmail(QString);
    void setNomeleve(QString);
    bool ajouter(Parent p);
    bool modifier (Parent p);
    bool supprimer(QString cinn);
    QSqlQueryModel * afficher();
    QSqlQueryModel *rechercherparent(QString);
    QSqlQueryModel *tri_nom();
     QSqlQueryModel *tri_nomeleve();
     QSqlQueryModel * getIdModel();
    bool verif_nom(QString nom);
    bool verif_CIN(QString CIN);
     bool verif_prenom(QString prenom);
     bool verif_nomeleve(QString nomeleve);
     bool verif_email(QString email);

    private:
    QString CIN ;
    QString numero ;
    QString nom , prenom , email , nomeleve;
};

#endif // CLIENT_H

