#include "membre.h"
#include <QString>
#include <QMessageBox>
member::member()
{id="";
    nom="";
    nc="";
    nbsc="";
    mail="";

}

member::member(QString id , QString nom ,QString nc,QString nbsc,QString mail)
{

    this->id=id ;
    this->nom=nom ;
    this->nc=nc ;
    this->nbsc=nbsc;
    this->mail=mail ;





}
QString  member::get_nom()
{ return nom ;}
QString member::get_nc()
{return nc;}
QString member::get_id()
{return id ;}
QString member::get_nbsc()
{return nbsc ;}
QString member::get_mail()
{return mail ;}


bool member::ajouter_m()
{

    QSqlQuery query ;

    query.prepare("INSERT INTO member (id,nom,nc,nbsc,mail)" "VALUES (:id , :nom , :nc , :nbsc ,:mail)");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":nc",nc);
    query.bindValue(":nbsc",nbsc);
    query.bindValue(":mail",mail);


    return query.exec();

}
QSqlQueryModel * member::afficher_m()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from member");

model->setHeaderData(0,Qt::Horizontal ,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal ,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal ,QObject::tr("nc"));
model->setHeaderData(3,Qt::Horizontal ,QObject::tr("nbsc"));
model->setHeaderData(4,Qt::Horizontal ,QObject::tr("mail"));

return model ;
}
bool member::supprimer_m(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from member where ID=:id");
    query.bindValue(":id",id);
    return query.exec();

}

bool member::modifier_m(member m)
{
    QSqlQuery query;


    query.prepare("UPDATE member SET  nom= :nom,nc = :nc,nbsc= :nbsc,mail= :mail WHERE id= :id");

    query.bindValue(":id",m.get_id());
    query.bindValue(":nom",m.get_nom());
    query.bindValue(":nc",m.get_nc());
    query.bindValue(":nbsc",m.get_nbsc());
    query.bindValue(":mail",m.get_mail());

    return query.exec();
}
QSqlQueryModel * member::afficher_memberlist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select mail from member");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("mail"));
    return model;
}


QSqlQueryModel * member::rechercher_m(QSqlQuery q)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery(q);
    return (model);
}
bool member::verif_idm(QString ch_id){
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
bool member::verif_nom(QString nom){
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

bool member::verif_email(QString ch){
   bool test=false;
   int i;
   for(i=0;i<ch.length();i++)
   {
       if(ch[i]=='@'){
           test=true;
       }
   }
   return  test;
}
