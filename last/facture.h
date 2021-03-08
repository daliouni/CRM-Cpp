#ifndef FACTURE_H
#define FACTURE_H
#include<QString>
#include "MainWindow.h"


#include"ui_MainWindow.h"
#include <QtSql/QSqlQueryModel>


class facture
{
private :
    QString code_facture;
    int code_commande;
    int montant;
    QString reglement;
    QString affaire;



public:
    facture();
    facture(QString,int,int,QString,QString);
    bool ajouter(Ui::MainWindow *ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);
    QSqlQueryModel * trierFacture();
    QSqlQueryModel * rechercherFacture(QString code_facture);

};

#endif // FACTURE_H
