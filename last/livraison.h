#ifndef LIVRAISON_H
#define LIVRAISON_H
#include "MainWindow.h"
#include "ui_MainWindow.h"


class livraison
{
private :

    QString locatisation ;
    int codefacture ;
    int codecommande ;
    QString nom_prenom;
    QString temps ;

public:
    livraison();
    livraison(QString,int,int,QString,QString);
    bool ajouter(Ui::MainWindow *ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool Modifier(Ui::MainWindow *ui);

};

#endif // LIVRAISON_H
