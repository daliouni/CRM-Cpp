#ifndef EVENEMENT_H
#define EVENEMENT_H


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDate>
#include <Qprinter>
#include <QString>
#include <QtSql/QSqlQueryModel>



class evenement
{
private:
    QString id ;
    QString nom_event ;
    QString date_event;
    QString lieu;
    int budget;
public:
    evenement();
    evenement(QString ,QString ,QString,QString,int);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    QSqlQueryModel * trierEvent();
    QSqlQueryModel *rechercherEvent(QString nom_event);
};


#endif // EVENEMENT_H
