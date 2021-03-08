#ifndef COMMANDE_H
#define COMMANDE_H
#include <Qstring>
#include <iostream>
#include "ui_MainWindow.h"
#include "MainWindow.h"
#include <QtSql/QSqlQueryModel>


class commande
{
private:
    QString nom_prenom;
    QString nom_produit;
    int quantite;
    int prix;
    int code_commande;



public:

    commande();
    commande(int,QString, QString, int, int);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    void Tri_Prix(Ui::MainWindow *ui);

    int get_code_commande(){return code_commande;}
    void set_code_commande(int Code_commande){code_commande=Code_commande;}
    QSqlQueryModel *trierCommande();
    QSqlQueryModel *rechercherCommande(QString code_commande);

};

#endif // COMMANDE_H
