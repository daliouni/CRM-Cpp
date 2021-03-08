#ifndef FACTURE_STOCK_H
#define FACTURE_STOCK_H
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


class facture_stock
{
private:
    int id_fournisseur;
    QString reference_produit;
    QString description ;
    int quantite ;
    int prix_unitaire;
    int taxe_devente ;
public:
    facture_stock();
    facture_stock(int,QString,QString,int,int,int);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);

};

#endif // FACTURE_STOCK_H
