#ifndef STOCK_H
#define STOCK_H
#include <QString>
#include <iostream>
#include <QtSql>
#include <QtSql/QSqlQueryModel>
#include "ui_mainwindow.h"
#include "mainwindow.h"



class stock
{
private :
    int code_produit;
    QString reference ;
    QString fournisseur;
    int prix;
    int remise;
    QString stock_produit;
public:
    stock();
    stock(int,QString,QString,int,int,QString);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    QSqlQueryModel * trierStock();
        QSqlQueryModel *rechercherStock(QString code_produit);
};

#endif // STOCK_H
