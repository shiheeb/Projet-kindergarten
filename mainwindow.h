#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "parent.h"
#include"reclamation.h"
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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_12_clicked();
    void initialiser();
    void initialiser_reclamation();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    //void on_pushButton_clicked();

   // void on_pb_supprimer_clicked();

    void on_pushButton_4_clicked();

  //  void on_pushButton_16_clicked();

    //void on_pushButton_8_clicked();

    //void on_pushButton_9_clicked();

    //void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();


    void on_pb_supprimer_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_17_clicked();

    void on_tabparent_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_12_clicked();

    void on_radioButton_19_clicked();

    void on_radioButton_20_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_19_clicked();

   // void on_num_2_cursorPositionChanged(int arg1, int arg2);

    void on_tablereclamation_2_activated(const QModelIndex &index);


    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;

    Parent tmpparent;
    Parent p ;
    Reclamation r ;
    Reclamation tmpreclamation;
          PopUp *popUp;
};
#endif // MAINWINDOW_H
