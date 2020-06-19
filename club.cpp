#include "club.h"
#include <QString>
#include <QMessageBox>
club::club()
{


id="";
nom="";
enca="";
numtt="";
datee="";
}

club::club(QString id , QString nom ,QString enca,QString datee,QString numtt)
{

    this->id=id ;
    this->nom=nom ;
    this->datee=datee ;
    this->enca=enca ;
    this->numtt=numtt ;





}
QString  club::get_nom()
{ return nom ;}
QString club::get_enca()
{return enca;}
QString club::get_id()
{return id ;}
QString club::get_datee()
{return datee ;}
QString club::get_numtt()
{return numtt ;}


bool club::ajouter_c()
{

    QSqlQuery query ;

    query.prepare("INSERT INTO club (id,nom,datee,enca,numtt)" "VALUES (:id , :nom , :datee , :enca ,:numtt)");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":datee",datee);
    query.bindValue(":enca",enca);
    query.bindValue(":numtt",numtt);


    return query.exec();

}
QSqlQueryModel * club::afficher_c()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from club");

model->setHeaderData(0,Qt::Horizontal ,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal ,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal ,QObject::tr("datee"));
model->setHeaderData(3,Qt::Horizontal ,QObject::tr("enca"));
model->setHeaderData(4,Qt::Horizontal ,QObject::tr("numtt"));

return model ;
}
bool club::supprimer_c(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from club where ID=:id");
    query.bindValue(":id",id);
    return query.exec();

}

bool club::modifier_c(club p)
{
    QSqlQuery query;


    query.prepare("UPDATE club SET  nom= :nom,enca= :enca,datee = :datee,numtt= :numtt WHERE id= :id");

    query.bindValue(":id",p.get_id());
    query.bindValue(":nom",p.get_nom());
    query.bindValue(":datee",p.get_datee());
    query.bindValue(":enca",p.get_enca());
    query.bindValue(":numtt",p.get_numtt());

    return query.exec();
}
QSqlQueryModel * club::afficher_clublist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select nom from club");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    return model;
}


QSqlQueryModel * club::rechercher_c(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}
bool club::verif_idc(QString ch_id){
   bool test=true;
   int i;
   if(ch_id.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<ch_id.length();i++){
           if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;
}
bool club::verif_nom(QString nom){
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

