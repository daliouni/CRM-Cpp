#ifndef LIV_H
#define LIV_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QAbstractItemModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>

class liv
{
private:
    QString nom_livraison;
    QString objet_livraison;
    QString quantite_livraison;
    QString date_livraison;
    QString adresse_livraison;
public:
    liv();
    liv(QString,QString,QString,QString,QString);
    bool ajouter();
        bool supprimer(QString objet_livraison);
        QSqlQueryModel* affichage(QString);
        bool modifier(QString,QString,QString,QString,QString);
        QSqlQueryModel* recherche(QString);
        QSqlQueryModel* affichagetout();
};

#endif // LIV_H
