#ifndef GESTION_CLUB_H
#define GESTION_CLUB_H

#include <QMainWindow>
#include <QMainWindow>
#include"club.h"
#include"popup.h"
#include<QtSql>
#include<QtCore>
#include<QtGui>
#include"membre.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_club; }
QT_END_NAMESPACE

class gestion_club : public QMainWindow
{
    Q_OBJECT

public:
    gestion_club(QWidget *parent = nullptr);
    ~gestion_club();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_tableView_club_activated(const QModelIndex &index);

    void on_pushButton_suprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_comboBox_m_activated(const QString &arg1);

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_suprimer_2_clicked();

    void on_tableView_membre_activated(const QModelIndex &index);

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_sendEmail_clicked();

    void on_pushButton_5_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_historique_evenements_clicked();

    void on_historique_evenements_3_clicked();

    void on_comboBox_m_3_activated(const QString &arg1);

    void on_lineEdit_nc_cursorPositionChanged(int arg1, int arg2);

    void on_recipients_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_4_clicked();

private:
    Ui::gestion_club *ui;
     PopUp *popUp;
     club tmpclub;
     member tmpmm;
};
#endif // GESTION_CLUB_H
