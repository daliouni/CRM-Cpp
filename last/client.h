#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QtSql/QSqlTableModel>
#include "ui_MainWindow.h"
#include "MainWindow.h"
#include <QtSql/QSqlQueryModel>


class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,QString,QString,QString,QString,QString);
    bool ajouter(Ui::MainWindow*ui);
    bool supprimer(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
    void Afficher(Ui::MainWindow *ui);
    void AfficherTable(Ui::MainWindow *ui);
    QSqlQueryModel *trierClient();
    QSqlQueryModel *rechercherClient(QString Nom);




private:
        QString CIN;
        QString Nom ;
        QString Prenom ;
        QString Age;
        QString Adresse;
        QString Email;
        QString Tel;
        QString Category;
        QString Sexe;
};

#endif // CLIENT_H
