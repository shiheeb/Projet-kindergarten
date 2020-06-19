#include "reclamation.h"
#include <QDebug>
Reclamation::Reclamation()
{
num ="";
eleve="";
parent="";
objet="";
prof="";


}
Reclamation::Reclamation(QString num,QString eleve,QString parent,QString objet,QString prof )
{
  this->num=num;
  this->eleve=eleve;
  this->parent=parent;
  this->objet=objet;
    this->prof=prof;


}


bool Reclamation::ajouter(Reclamation r)
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABRECLAMATION (NUM, ELEVE, PARENT, OBJET, PROF) "
                        "VALUES (:num, :eleve, :parent, :objet, :prof)");
    query.bindValue(":num",r.get_num());
    query.bindValue(":eleve",r.get_eleve());
    query.bindValue(":parent",r.get_parent());
    query.bindValue(":objet",r.get_objet());
    query.bindValue(":prof",r.get_prof());

    return query.exec();
}


QSqlQueryModel * Reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABRECLAMATION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eleve "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Parent"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Objet"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prof"));

    return model;
}

bool Reclamation::supprimer(QString Numm)
{
QSqlQuery query;

query.prepare("Delete from TABRECLAMATION where NUM = :NUM ");
query.bindValue(":NUM", Numm);
return    query.exec();
}
bool Reclamation::modifier(Reclamation r)
{
    QSqlQuery query;

       query.prepare("UPDATE TABRECLAMATION SET NUM =:num , ELEVE =:eleve , PARENT =:parent ,OBJET =:objet ,PROF=:prof WHERE NUM =:num ");
       query.bindValue(":num",r.get_num());
       query.bindValue(":eleve",r.get_eleve());
       query.bindValue(":parent",r.get_parent());
       query.bindValue(":objet",r.get_objet());
       query.bindValue(":prof",r.get_prof());

    return query.exec();
}
QSqlQueryModel *Reclamation::tri_num()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABRECLAMATION ORDER BY NUM");
q->exec();
model->setQuery(*q);
return model;
}
QSqlQueryModel *Reclamation::tri_nom()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABRECLAMATION ORDER BY PARENT");
q->exec();
model->setQuery(*q);
return model;
}
QSqlQueryModel * Reclamation::getIdModel()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select NOMELEVE from TABPARENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ELEVE"));
        return model;
}

/*QSqlQueryModel *Reclamation::rechercher_eleve(QSqlQuery q)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM TABRECLAMATION WHERE ELEVE like '"+eleve+"%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eleve "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Parent"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Objet"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prof"));
return model;


}*/
QSqlQueryModel *Reclamation::rechercher_num(QString num)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM TABRECLAMATION WHERE NUM like '"+num+"%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Eleve "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Parent"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Objet"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prof"));
return model;

}
bool Reclamation::verif_num(QString numm){
   bool test=true;
   int i;
   if(numm.length()!=4){
      test=false;
      return  test;
   }else{
       for(i=0;i<numm.length();i++){
           if(!((numm[i]>='0')&&(numm[i]<='5'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool Reclamation::verif_prof(QString prof){
    bool test=true;
    int i;
    if(prof.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<prof.length();i++){
            if(!(((prof[i]>='A')&&(prof[i]<='Z'))||((prof[i]>='a')&&(prof[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
bool Reclamation::verif_parent(QString parent){
    bool test=true;
    int i;
    if(parent.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<parent.length();i++){
            if(!(((parent[i]>='A')&&(parent[i]<='Z'))||((parent[i]>='a')&&(parent[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}
bool Reclamation::verif_eleve(QString eleve){
    bool test=true;
    int i;
    if(eleve.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<eleve.length();i++){
            if(!(((eleve[i]>='A')&&(eleve[i]<='Z'))||((eleve[i]>='a')&&(eleve[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}



