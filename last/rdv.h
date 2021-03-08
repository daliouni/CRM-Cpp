#ifndef RDV_H
#define RDV_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QAbstractItemModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>

class rdv
{
private:
    QString nom_client;
    QString prenom_client;
    QString adresse_client;
    QString sexe_client;
    QString code_rdv;
    QString date_rdv;
public:
    rdv();
    rdv(QString,QString,QString,QString,QString,QString);
    bool ajouter();
        bool supprimer(QString code_rdv);
        QSqlQueryModel* affichage(QString);
        bool modifier(QString,QString,QString,QString,QString,QString);
        QSqlQueryModel* recherche(QString);
        QSqlQueryModel* affichagetout();
};

#endif // RDV_H
