#include "gestion_club.h"
#include"connexion.h"
#include <QApplication>
#include"club.h"
#include <QString>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;

    bool test=c.ouvrirConnexion();
     gestion_club w;
    if(test)
    {w.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
