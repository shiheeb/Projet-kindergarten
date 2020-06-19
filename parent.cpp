#include "parent.h"
#include <QDebug>
Parent::Parent()
{
CIN ="";
nom="";
prenom="";
email="";
numero="";
nomeleve="";

}
Parent::Parent(QString CIN,QString nom,QString prenom ,QString email ,QString numero,  QString nomeleve )
{
  this->CIN=CIN;
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->numero=numero ;
   this->nomeleve=nomeleve ;

}


bool Parent::ajouter(Parent p)
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABPARENT (CIN, NOM, PRENOM, EMAIL, NUMERO, NOMELEVE) "
                        "VALUES (:cin, :nom, :prenom, :email, :numero, :nomeleve)");
    query.bindValue(":cin",p.get_CIN());
    query.bindValue(":nom",p.get_nom());
    query.bindValue(":prenom",p.get_prenom());
    query.bindValue("email",p.get_email());
    query.bindValue(":numero",p.get_num());
    query.bindValue(":nomeleve",p.get_nomeleve());
    return query.exec();
}


QSqlQueryModel * Parent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABPARENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nomeleve"));
    return model;
}

bool Parent::supprimer(QString CINN)
{
QSqlQuery query;

query.prepare("Delete from TABPARENT where CIN = :CIN ");
query.bindValue(":CIN", CINN);
return    query.exec();
}
bool Parent::modifier(Parent p)
{
    QSqlQuery query;

       query.prepare("UPDATE TABPARENT SET NOM =:nom , PRENOM =:prenom , EMAIL =:email ,NUMERO =:numero ,NOMELEVE =:nomeleve WHERE CIN =:cin ");
       query.bindValue(":cin", p.get_CIN());
       query.bindValue(":nom", p.get_nom());
       query.bindValue(":prenom",p.get_prenom());
       query.bindValue(":email", p.get_email());
       query.bindValue(":numero", p.get_num());
       query.bindValue(":nomeleve",p.get_nomeleve());
    return query.exec();
}
QSqlQueryModel *Parent::tri_nom()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABPARENT ORDER BY NOM");
q->exec();
model->setQuery(*q);
return model;
}
QSqlQueryModel *Parent::tri_nomeleve()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABPARENT ORDER BY NOMELEVE");
q->exec();
model->setQuery(*q);
return model;
}

QSqlQueryModel *Parent::rechercherparent(QString nom)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM TABPARENT WHERE NOM like '"+nom+"%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nomeleve"));
return model;

}
bool Parent::verif_CIN(QString CINN){
   bool test=true;
   int i;
   if(CINN.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<CINN.length();i++){
           if(!((CINN[i]>='0')&&(CINN[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool Parent::verif_nom(QString nom){
    bool test=true;
    int i;
    if(nom.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
bool Parent::verif_prenom(QString prenom){
    bool test=true;
    int i;
    if(prenom.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<prenom.length();i++){
            if(!(((prenom[i]>='A')&&(prenom[i]<='Z'))||((prenom[i]>='a')&&(prenom[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
bool Parent::verif_nomeleve(QString nomeleve){
    bool test=true;
    int i;
    if(nomeleve.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<nomeleve.length();i++){
            if(!(((nomeleve[i]>='A')&&(nomeleve[i]<='Z'))||((nomeleve[i]>='a')&&(nomeleve[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
QSqlQueryModel * Parent::getIdModel()
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    query->prepare("select idClient from TABCLIENT");
    query->exec();
    model->setQuery(*query);
    return model;
}
bool Parent::verif_email(QString email){
   bool test=false;
   int i;
   for(i=0;i<email.length();i++)
   {
       if(email[i]=='@'){
           test=true;
       }
   }
   return  test;
}
