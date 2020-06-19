#include "gestion_club.h"
#include "ui_gestion_club.h"
#include"popup.h"
#include"club.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>
#include "SmtpMime"
#include "QTextDocument "
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QDesktopServices>
#include"QTextDocumentWriter"
#include "statisitique_club.h"
#include "ui_statisitique_club.h"
#include <QSqlQuery>
#include <QDesktopServices>
#include <QDialog>
#include"membre.h"

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

#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>

#include <QtWidgets/QGridLayout>
gestion_club::gestion_club(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_club)
{
    ui->setupUi(this);
    ui->tableView_club->setModel(tmpclub.afficher_c());
     ui->tableView_membre->setModel(tmpmm.afficher_m());
     ui->comboBox_m->setModel(tmpclub.afficher_clublist());
    ui->comboBox_m_3->setModel(tmpmm.afficher_memberlist());
        popUp = new PopUp();
        popUp->setPopupText("Welcome kids");
        popUp->show();

}

gestion_club::~gestion_club()
{
    delete ui;
}


void gestion_club::on_pushButton_ajouter_clicked()
{
    QString id =ui->lineEdit_id->text();
    QString nom=ui->lineEdit_nom->text();
    QString datee= ui->dateEdit_evenements->text();
    QString enca=ui->lineEdit_enca->text();
    QString numtt=ui->lineEdit_membre->text();


    club p(id,nom,datee,enca,numtt);

    if(p.verif_idc(id)==false){
        popUp = new PopUp();
                    popUp->setPopupText("l'id doit contenir 8 chiffre ");
                    popUp->show();



     }else if(nom==""){
        popUp = new PopUp();
                    popUp->setPopupText("verifiez le champ nom ");
                    popUp->show();
    }else if(enca==""){
        popUp = new PopUp();
                    popUp->setPopupText("verifiez le champ enca ");
                    popUp->show();

     }
    else if(numtt==""){
        popUp = new PopUp();
                    popUp->setPopupText("verifiez le champ duree ");
                    popUp->show();

         }
    else{

    bool test=p.ajouter_c();

    if(test)
    {
    ui->tableView_club->setModel(tmpclub.afficher_c());

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select nom from club");
    ui->comboBox_m->setModel(model);

       qDebug()<<"table actualise";
    QFile file("G:\\c++tri\\h.txt");
                   if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                       return;
                   QTextStream cout(&file);
                   QString message2="\n L'historique des club à ajouter :"+id+" "+nom+" "+datee+" "+enca+" "+numtt;
                   cout << message2;

    }


}


}

void gestion_club::on_tableView_club_activated(const QModelIndex &index)
{

    QString val=ui->tableView_club->model()->data(index).toString();


        QSqlQuery qry;
        qry.prepare("select * from club where  id='"+val+"' or nom='"+val+"' or enca='"+val+"' or datee='"+val+"' or numtt='"+val+"'");

    if(qry.exec())
    {

    while(qry.next())
    {

        ui->lineEdit_id->setText(qry.value(0).toString());
        ui->lineEdit_nom->setText(qry.value(1).toString());
        ui->lineEdit_enca->setText(qry.value(3).toString());
        ui->dateEdit_evenements->setDate(qry.value(2).toDate());
        ui->lineEdit_membre->setText(qry.value(4).toString());


}
}

}

void gestion_club::on_pushButton_suprimer_clicked()
{
    int id =ui->lineEdit_id->text().toInt();
       bool test=tmpclub.supprimer_c(id);

       if(test)
     {
     ui->tableView_club->setModel(tmpclub.afficher_c());



     QMessageBox::information(nullptr, windowTitle(),QObject::tr("Supprimer succés"));
     }
       else
       {
           QMessageBox::information(nullptr, windowTitle(),QObject::tr("Id n'existe pas"));
   }
}

void gestion_club::on_pushButton_modifier_clicked()
{

    QString id =ui->lineEdit_id->text();
   QString nom=ui->lineEdit_nom->text();
     QString datee= ui->dateEdit_evenements->text();
   QString enca= ui->lineEdit_enca->text();

   QString numtt= ui->lineEdit_membre->text();


    club p(id,nom,datee,enca,numtt);

    bool test=false;
         if (id>0)test=tmpclub.modifier_c(p);
        {
             ui->tableView_club->setModel(tmpclub.afficher_c());

            QMessageBox::information(this,"promo supprime","ce promo a ete modifie");
        }
}





void gestion_club::on_comboBox_m_activated(const QString &arg1)
{
      ui->lineEdit_nc->setText(arg1);
}

void gestion_club::on_pushButton_ajouter_2_clicked()
{

    QString id =ui->lineEdit_id_2->text();
    QString nom=ui->lineEdit_nom_2->text();
    QString nc= ui->lineEdit_nc->text();
    QString nbsc=ui->lineEdit_nnbs->text();
    QString mail=ui->lineEdit_mail->text();


    member m(id,nom,nc,nbsc,mail);

    if(m.verif_idm(id)==false){


        popUp = new PopUp();
                    popUp->setPopupText("l'id doit contenir 8 chiffre ");
                    popUp->show();

     }else if(nom==""){
        popUp = new PopUp();
                    popUp->setPopupText("l'id doit contenir 8 chiffre ");
                    popUp->show();

    }else if(nc==""){

                        popUp = new PopUp();
                                    popUp->setPopupText("l'id doit contenir 8 chiffre ");
                                    popUp->show();
     }
    else if(nbsc==""){

                        popUp = new PopUp();
                                    popUp->setPopupText("l'id doitverif_email contenir 8 chiffre ");
                                    popUp->show();
         }
    else if (m.verif_email(mail)==false){
        popUp = new PopUp();
                    popUp->setPopupText("l'id doit contenir un email  @ ");
                    popUp->show();


    }

    else{

    bool test=m.ajouter_m();

    if(test)
    {
    ui->tableView_membre->setModel(tmpmm.afficher_m());

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select mail from member");
   ui->comboBox_m_3->setModel(model);

       qDebug()<<"table actualise";
    QFile file("G:\\c++tri\\hm.txt");
                   if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                       return;
                   QTextStream cout(&file);
                   QString message2="\n L'historique de membre à ajouter :"+id+" "+nom+" "+nc+" "+nbsc+" "+mail;
                   cout << message2;

    }


}


}

void gestion_club::on_pushButton_modifier_2_clicked()
{

    QString id =ui->lineEdit_id_2->text();
    QString nom=ui->lineEdit_nom_2->text();
    QString nc= ui->lineEdit_nc->text();
    QString nbsc=ui->lineEdit_nnbs->text();
    QString mail=ui->lineEdit_mail->text();


    member m(id,nom,nc,nbsc,mail);

    bool test=false;
         if (id>0)test=tmpmm.modifier_m(m);
        {
             ui->tableView_membre->setModel(tmpmm.afficher_m());

            QMessageBox::information(this,"promo supprime","ce promo a ete modifie");
        }
}

void gestion_club::on_pushButton_suprimer_2_clicked()
{
    int id =ui->lineEdit_id_2->text().toInt();
       bool test=tmpmm.supprimer_m(id);

       if(test)
     {
     ui->tableView_membre->setModel(tmpmm.afficher_m());



     QMessageBox::information(nullptr, windowTitle(),QObject::tr("Supprimer succés"));
     }
       else
       {
           QMessageBox::information(nullptr, windowTitle(),QObject::tr("Id n'existe pas"));
   }
}

void gestion_club::on_tableView_membre_activated(const QModelIndex &index)
{
    QString val=ui->tableView_membre->model()->data(index).toString();


        QSqlQuery qry;
        qry.prepare("select * from member where  id='"+val+"'");

    if(qry.exec())
    {

    while(qry.next())
    {

        ui->lineEdit_id_2->setText(qry.value(0).toString());
        ui->lineEdit_nom_2->setText(qry.value(1).toString());
        ui->lineEdit_nc->setText(qry.value(2).toString());
        ui->lineEdit_nnbs->setText(qry.value(3).toString());
        ui->lineEdit_mail->setText(qry.value(4).toString());


}
}
}

void gestion_club::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from member ORDER BY id ");


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nc"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbsc"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
   ui->tableView_membre->setModel(model) ;
}

void gestion_club::on_radioButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from member ORDER BY id desc");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nc"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbsc"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
   ui->tableView_membre->setModel(model) ;

}

void gestion_club::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
            QSqlQuery q;
            q.prepare("select * from member WHERE ID like '"+ui->lineEdit_4->text()+"' OR  NOM like '"+ui->lineEdit_4->text()+"' OR nc like '"+ui->lineEdit_4->text()+"' ");
                tmpmm.rechercher_m(q);
                   q.exec();
                    model->setQuery(q);
                   ui->tableView_membre->setModel(tmpmm.rechercher_m(q));
}

void gestion_club::on_sendEmail_clicked()
{

    // This is a first demo application of the SmtpClient for Qt project

       // First we need to create an SmtpClient object
       // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

       SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

       // We need to set the username (your email address) and the password
       // for smtp authentification.

       smtp.setUser("yassine.bensalem@esprit.tn");
       smtp.setPassword("181JMT2772");

       // Now we create a MimeMessage object. This will be the email.

       MimeMessage message;
       QString addr = ui->recipients->text();
       QString objet = ui->subject->text();

       message.setSender(new EmailAddress("yassine.bensalem@esprit.tn", "Kids"));
       message.addRecipient(new EmailAddress(addr, ""));
       message.setSubject(objet);

       // Now add some text to the email.
       // First we create a MimeText object.

       MimeText text;

       QString msg = ui->texteditor->toPlainText();

       text.setText(msg);

       // Now add it to the mail

       message.addPart(&text);

       // Now we can send the mail

       smtp.connectToHost();
       smtp.login();
       smtp.sendMail(message);
       smtp.quit();
}

void gestion_club::on_pushButton_5_clicked()
{
    /*  QPrinter printer;
                  QString doc;

                  printer.setPrinterName("printer1");
                  QPrintDialog print_dialog(&printer,this);
                 if(print_dialog.exec()== QDialog::Rejected) return ;

                   ui->text_id-> */


            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView_club->model()->rowCount();
            const int columnCount = ui->tableView_club->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                 <<  QString("<title>%1</title>\n").arg("col1")
                  <<  "</head>\n"
                      "  <h1>Gestion des clients PDF</h1>"
                      "<body bgcolor=#7ebbbd  link=#5000A0>\n"
                      "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView_club->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView_club->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_club->isColumnHidden(column)) {
                        QString data = ui->tableView_club->model()->data(ui->tableView_club->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void gestion_club::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from club ORDER BY id ");


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("enca"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtt"));
   ui->tableView_club->setModel(model) ;
}

void gestion_club::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from club ORDER BY id desc");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("enca"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtt"));
   ui->tableView_club->setModel(model) ;
}

void gestion_club::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QSqlQueryModel * model= new QSqlQueryModel();
            QSqlQuery q;
            q.prepare("select * from club WHERE ID like '"+ui->lineEdit->text()+"' OR  NOM like '"+ui->lineEdit->text()+"' OR enca like '"+ui->lineEdit->text()+"' ");
                tmpclub.rechercher_c(q);
                   q.exec();
                   model->setQuery(q);
                   ui->tableView_club->setModel(tmpclub.rechercher_c(q));
}

void gestion_club::on_pushButton_6_clicked()
{

    ui->tableView_club->setModel(tmpclub.afficher_c());
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select id from club");
        qDebug()<<"table actualise";
}

void gestion_club::on_pushButton_7_clicked()
{ ui->tableView_membre->setModel(tmpmm.afficher_m());
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select id from membre");
    qDebug()<<"table actualise";

}

void gestion_club::on_pushButton_9_clicked()
{
    /*  QPrinter printer;
                  QString doc;

                  printer.setPrinterName("printer1");
                  QPrintDialog print_dialog(&printer,this);
                 if(print_dialog.exec()== QDialog::Rejected) return ;

                   ui->text_id-> */


            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView_membre->model()->rowCount();
            const int columnCount = ui->tableView_membre->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                 <<  QString("<title>%1</title>\n").arg("col1")
                  <<  "</head>\n"
                      "  <h1>Gestion des clients PDF</h1>"
                      "<body bgcolor=#7ebbbd  link=#5000A0>\n"
                      "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView_membre->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView_membre->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_membre->isColumnHidden(column)) {
                        QString data = ui->tableView_membre->model()->data(ui->tableView_membre->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void gestion_club::on_historique_evenements_clicked()
{ QFile file ("G:\\c++tri\\h.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_club->setText(in.readAll());

}

void gestion_club::on_historique_evenements_3_clicked()
{
    QFile file ("G:\\c++tri\\hm.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
       ui->historique_club_3->setText(in.readAll());
}

void gestion_club::on_comboBox_m_3_activated(const QString &arg1)
{
     ui->recipients->setText(arg1);
}


void gestion_club::on_pushButton_4_clicked()
{
    statisitique_club *s = new statisitique_club();
           setWindowModality(Qt::WindowModal);
           s->show();
}
