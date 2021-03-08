#ifndef DEMANDE_H
#define DEMANDE_H
#include <QString>
#include <iostream>
#include "ui_MainWindow.h"
#include "MainWindow.h"


class demande
{
private :
    QString num_demande ;
    QString sujet ;
    QString description;


public:
    demande();
    demande(QString,QString,QString);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);

};

#endif // DEMANDE_H
