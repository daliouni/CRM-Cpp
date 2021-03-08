#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <iostream>
#include <QDebug>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>

#define q2c(string) string.toStdString()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setUserName("SYSTEM");
    db.setPassword("hello123");
    db.setDatabaseName("CRM");
   QSqlQuery q;
    if(db.open())
    {
        std::cout << "Vous êtes mainten ant connecté à " << q2c(db.hostName()) << std::endl;
        //db.close();
    }
    else
    {
        std::cout << "La connexion a échouée, désolé" << std::endl;
    //qDebug()<<"erreur:"<<db.lastError().text();

    }
    w.show();

    return a.exec();
}
