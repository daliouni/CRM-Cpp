#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <iostream>
#include "ui_MainWindow.h"
#include "MainWindow.h"


class reclamation
{
private :
    QString num_reclamation ;
    QString sujet ;
    QString description;


public:
    reclamation();
    reclamation(QString,QString,QString);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);

};

#endif // DEMANDE_H
