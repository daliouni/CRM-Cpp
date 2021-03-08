#ifndef OFFRE_H
#define OFFRE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDate>
#include <Qprinter>
#include <QString>
#include <QtSql/QSqlQueryModel>




class offre
{
private:
    QString nom ;
    QString id ;
    QString client_cible;
    QString date;
public:
    offre();
    offre(QString ,QString ,QString,QString);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    QSqlQueryModel * trierOffre();
    QSqlQueryModel *rechercherOffre(QString nom);
};

#endif // OFFRE_H
