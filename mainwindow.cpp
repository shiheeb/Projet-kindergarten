#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parent.h"
#include"smtp.h"
#include "reclamation.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>
#include"QMessageBox"
#include<QPropertyAnimation>
#include<random>
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <QTableWidget>
#include <QFile>
#include <popup.h>
#include <QSqlError>
#include <QtWidgets/QGridLayout>
#include <QMainWindow>
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabparent->setModel(tmpparent.afficher());
ui->tablereclamation_2->setModel(tmpreclamation.afficher());
 ui->comboBox->setModel(r.getIdModel());
popUp = new PopUp();
popUp->setPopupText("bienvenue chez KIDZIA");
popUp->show();}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialiser()
{
                ui->lineEdit_CIN_2->clear();
             ui->lineEdit_nom_2->clear();
             ui->lineEdit_prenom_2->clear();
             ui->lineEdit_email_3->clear();
            ui->lineEdit_num_2->clear();
            ui->nomeleve1_2->clear();

}

void MainWindow::initialiser_reclamation()
{
         ui->num->clear();
         ui->parent->clear();
         ui->comboBox->clear();
         ui->objet->clear();
      ui->prof->clear(); }

//recherche parent
void MainWindow::on_pushButton_2_clicked()
{
    QString nom =ui->CIN2_2->text();



     bool test=tmpparent.rechercherparent(nom);
     if (test)
     {ui->tabparent->setModel(tmpparent.rechercherparent(nom));
         QMessageBox::information(nullptr, QObject::tr("Rechercher un parent"),
                           QObject::tr(" parent existe!.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
     else

     QMessageBox::critical(nullptr, QObject::tr("Rechercher un parent"),
                 QObject::tr("Erreur !.\n"
                             "Try again"), QMessageBox::Retry);
}







//actualiser parent
void MainWindow::on_pushButton_13_clicked()
{
    int i;
      ui->tabparent->setModel(p.afficher());
      qDebug()<<ui->tabparent->model()->rowCount();
      for (i=0;i<ui->tabparent->model()->rowCount();i++)
      {
      ui->tabparent->model()->index(i,0).data().toString();
      }
}

//supprimer parent
void MainWindow::on_pb_supprimer_2_clicked()
{

    QString CIN= ui->lineEdit_CIN_2->text();
    bool test=tmpparent.supprimer(CIN);
           initialiser();
           if(test)
         {
         ui->tabparent->setModel(tmpparent.afficher());



         QMessageBox::information(nullptr, windowTitle(),QObject::tr("Suppression avec succés"));
         }
           else
           {
               QMessageBox::information(nullptr, windowTitle(),QObject::tr("CIN n'existe pas"));
       }
}
//tri nom
void MainWindow::on_radioButton_3_clicked()
{Parent pp;
    QSqlQueryModel * p=pp.tri_nom();
    ui->tabparent->setModel(tmpparent.tri_nom());
    ui->tabparent->setModel(p);

}
//tri cin
void MainWindow::on_radioButton_4_clicked()
{
    Parent pp;
        QSqlQueryModel * p=pp.tri_nomeleve();
        ui->tabparent->setModel(tmpparent.tri_nom());
        ui->tabparent->setModel(p);
}
//ajout parent
void MainWindow::on_pushButton_17_clicked()
{
    QString CIN=ui->lineEdit_CIN_2->text();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString email= ui->lineEdit_email_3->text();
    QString numero = ui->lineEdit_num_2->text();
    QString eleve = ui->nomeleve1_2->text();
    Parent p(CIN,nom,prenom,email,numero,eleve);
    bool test= p.ajouter(p);
  if(test)
{ui->tabparent->setModel(tmpparent.afficher());//refresh
/*QMessageBox::information(nullptr, QObject::tr("Ajouter un parent"),
                  QObject::tr("parent ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/

}
  if(p.verif_email(email)==false){
      popUp = new PopUp();
      popUp->setPopupText("email eleve  doit pas contenir @ !");
      popUp->show();

   }else if(p.verif_CIN(CIN)==false){
      popUp = new PopUp();
      popUp->setPopupText("CIN doit contenir 8 chiffres ! ");
      popUp->show();


   }else if(nom==""){
      popUp = new PopUp();
      popUp->setPopupText("nom ne  doit pas contenir des symboles! ");
      popUp->show();
  }else if(eleve==""){
      popUp = new PopUp();
      popUp->setPopupText("nom eleve ne  doit pas contenir des symboles!");
      popUp->show();

   }else if(prenom==""){
      popUp = new PopUp();
      popUp->setPopupText("prenom eleve ne  doit pas contenir des symboles!");
      popUp->show();

   }
   else{
      popUp = new PopUp();
      popUp->setPopupText("Parent ajouté avec success!");
      popUp->show();
    }
}
//modifier parent
void MainWindow::on_pushButton_3_clicked()
{ QSqlQuery query;

        QString CIN=ui->lineEdit_CIN_2->text();
        QString nom= ui->lineEdit_nom_2->text();
        QString prenom= ui->lineEdit_prenom_2->text();
        QString email= ui->lineEdit_email_3->text();
        QString numero = ui->lineEdit_num_2->text();
        QString eleve = ui->nomeleve1_2->text();

   Parent p(CIN,nom,prenom,email,numero,eleve);


   bool test=false;

        if (CIN>1)test=tmpparent.modifier(p);
       {
            ui->tabparent->setModel(tmpparent.afficher());

           QMessageBox::information(this,"parent supprime","parent modifie");
       }

}
//doubleclick
void MainWindow::on_tabparent_activated(const QModelIndex &index)
{
    QString val=ui->tabparent->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from tabparent where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"'or email='"+val+"'or numero='"+val+"'or nomeleve='"+val+"'");

if(qry.exec())
{

while(qry.next())
{

    ui->lineEdit_CIN_2->setText(qry.value(0).toString());
    ui->lineEdit_nom_2->setText(qry.value(1).toString());
    ui->lineEdit_prenom_2->setText(qry.value(2).toString());
     ui->lineEdit_email_3->setText(qry.value(3).toString());
      ui->lineEdit_num_2->setText(qry.value(4).toString());
       ui->nomeleve1_2->setText(qry.value(5).toString());

}
}
else
{
    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}
}
//imprimer parent

void MainWindow::on_pushButton_5_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("parent.pdf");
            printer.setPageMargins(12, 16, 12, 20, QPrinter::Millimeter);
            printer.setFullPage(false);

            QPainter painter(&printer);

            double xscale = printer.pageRect().width() / double(ui->tabparent->width());
            double yscale = printer.pageRect().height() / double(ui->tabparent->height());
            double scale = qMin(xscale, yscale);
            painter.translate(printer.paperRect().center());
            painter.scale(scale, scale);
            painter.translate(-ui->tabparent->width()/2, -ui->tabparent->height()/2);
            ui->tabparent->render(&painter);


}

//ajout reclamation
void MainWindow::on_pushButton_4_clicked()
{   QString num=ui->num->text();
    QString parent= ui->parent->text();
       QString eleve=ui->comboBox->currentText();
    QString objet= ui->objet->text();
    QString prof = ui->prof->text();
    Reclamation r (num,eleve,parent,objet,prof);

    if(r.verif_num(num)==false){
                popUp = new PopUp();
                popUp->setPopupText("num doit contenir 8 chiffres ! ");
                popUp->show();

             }else if((eleve=="")&&(r.verif_eleve(eleve)==false)){
                popUp = new PopUp();
                popUp->setPopupText(" veuillez remplir le champ eleve ! ");
                popUp->setPopupText(" nom eleve ne doit pas contenir des suymboles ! ");
                popUp->show();

             }else if((parent=="")&&(r.verif_parent(parent)==false)){
                popUp = new PopUp();
                popUp->setPopupText("veuillez remplir le champ prarent ! ");
                 popUp->setPopupText(" parent ne doit pas contenir des suymboles ! ");
                popUp->show();

             }if((prof=="")&&(r.verif_prof(prof)==false)){
                popUp = new PopUp();
                popUp->setPopupText("verifiez le champ prof ");
                 popUp->setPopupText(" prof ne doit pas contenir des suymboles ! ");
                popUp->show();

            }else if(objet==""){
               popUp = new PopUp();
               popUp->setPopupText("veuillez remplir le champ objet ! ");
               popUp->show();
             }
else {   bool test= r.ajouter(r);
        if(test)
               {
                  ui->tablereclamation_2->setModel(tmpreclamation.afficher());
                initialiser_reclamation();}

}
}
//actualiser reclamation

void MainWindow::on_pushButton_18_clicked()
{
    int i;
         ui->tablereclamation_2->setModel(r.afficher());
         qDebug()<<ui->tablereclamation_2->model()->rowCount();
         for (i=0;i<ui->tablereclamation_2->model()->rowCount();i++)
         {
       // ui->tableavis->model()->index(i,0).data().toString();

         ui->comboBox->addItem(ui->tablereclamation_2->model()->index(i,0).data().toString());
         }
         QSqlQueryModel *model= new QSqlQueryModel();
         model->setQuery(("select ELEVE from TABPARENT"));
         ui->comboBox->setModel(model);
}
//supprimer reclamation
void MainWindow::on_pushButton_12_clicked()
{
    QString num= ui->num->text();
        bool test=tmpreclamation.supprimer(num);
               initialiser_reclamation();
               if(test)
             {
             ui->tablereclamation_2->setModel(tmpreclamation.afficher());



             QMessageBox::information(nullptr, windowTitle(),QObject::tr("Suppression avec succés"));
             }
               else
               {
                   QMessageBox::information(nullptr, windowTitle(),QObject::tr("num reclamation n'existe pas"));
           }
}

//tri num
void MainWindow::on_radioButton_19_clicked()
{Reclamation rr;
    QSqlQueryModel * r=rr.tri_num();
    ui->tablereclamation_2->setModel(tmpreclamation.tri_num());
    ui->tablereclamation_2->setModel(r);


}
//tri nom


void MainWindow::on_radioButton_20_clicked()
{
    Reclamation rr;
        QSqlQueryModel * r=rr.tri_nom();
        ui->tablereclamation_2->setModel(tmpreclamation.tri_nom());
        ui->tablereclamation_2->setModel(r);

}

void MainWindow::on_pushButton_10_clicked()
{

    QSqlQuery query;
    QString num=ui->num->text();
        QString parent= ui->parent->text();
        QString eleve= ui->comboBox->currentText();
        QString objet= ui->objet->text();
        QString prof = ui->prof->text();
        Reclamation r (num,eleve,parent,objet,prof);


    bool test=false;

         if (num>0)test=tmpreclamation.modifier(r);
        {
             ui->tablereclamation_2->setModel(tmpreclamation.afficher());

            QMessageBox::information(this,"reclamation supprime","reclamation modifie");
        }
}

void MainWindow::on_pushButton_19_clicked()
{
    QString num =ui->num_2->text();



     bool test=tmpreclamation.rechercher_num(num);
     if (test)
     {ui->tablereclamation_2->setModel(tmpreclamation.rechercher_num(num));
         QMessageBox::information(nullptr, QObject::tr("Rechercher une reclamtion"),
                           QObject::tr(" reclamation existe  pas.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
     else

     QMessageBox::critical(nullptr, QObject::tr("Rechercher une reclamation"),
                 QObject::tr("Erreur !.\n"
                             "Try again"), QMessageBox::Retry);
}



void MainWindow::on_tablereclamation_2_activated(const QModelIndex &index)
{
    QString val=ui->tablereclamation_2->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from TABRECLAMATION where NUM='"+val+"' or ELEVE='"+val+"' or PARENT='"+val+"'or OBJET='"+val+"'or PROF='"+val+"'");

if(qry.exec())
{

while(qry.next())
{

    ui->num->setText(qry.value(0).toString());
    ui->parent->setText(qry.value(2).toString());
   ui->comboBox->setEditText(qry.value(1).toString());
     ui->objet->setText(qry.value(3).toString());
      ui->prof->setText(qry.value(4).toString());


}
}
}



void MainWindow::on_pushButton_clicked()
{    Smtp* smtp = new Smtp("hibouba.sboui@gmail.com", "KIDZIA", "smtp.gmail.com", 465);
     connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
         smtp->sendMail("hibouba.sboui@gmail.com", "shiheb.soltani@esprit.tn" , "Reclamation KIDZIA","Bonjour cher parent ");
}

void MainWindow::on_pushButton_6_clicked()
{

    QPrinter printer(QPrinter::HighResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("reclamation.pdf");
            printer.setPageMargins(12, 16, 12, 20, QPrinter::Millimeter);
            printer.setFullPage(false);

            QPainter painter(&printer);

            double xscale = printer.pageRect().width() / double(ui->tablereclamation_2->width());
            double yscale = printer.pageRect().height() / double(ui->tablereclamation_2->height());
            double scale = qMin(xscale, yscale);
            painter.translate(printer.paperRect().center());
            painter.scale(scale, scale);
            painter.translate(-ui->tablereclamation_2->width()/2, -ui->tablereclamation_2->height()/2);
            ui->tabparent->render(&painter);
}
