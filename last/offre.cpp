#include "offre.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <iostream>
#include <QMessageBox>

offre::offre()
{
    nom="";
    id="";
    date="";
    client_cible="";


}
offre::offre(QString nom,QString id,QString date,QString client_cible)
{
    this->nom=nom;
    this->id=id;
    this->date=date;
    this->client_cible=client_cible;

}
bool offre::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into OFFRE(nom, id ,date_offre,client_cible) VALUES (:nom, :id, :date_offre,:client_cible)");
        q.bindValue(":nom",ui->lineEdit_11->text());
        q.bindValue(":id",ui->lineEdit_45->text());
        q.bindValue(":date_offre",ui->lineEdit_46->text());
        q.bindValue(":client_cible",ui->lineEdit_47->text());
        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("l'offre a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("l'offre n'est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool offre::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update OFFRE set ID=:id,DATE_OFFRE=:date_offre ,CLIENT_CIBLE=:client_cible where  NOM=:nom" );
    q.bindValue(":nom",ui->lineEdit_11->text());
    q.bindValue(":id",ui->lineEdit_45->text());
    q.bindValue(":client_cible",ui->lineEdit_46->text());
    q.bindValue(":date_offre",ui->lineEdit_47->text());
    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("l'offre a ete ajoute ");
                msgBox.exec();
        return true;
    }
    else
{
        QMessageBox msgBox ;
                msgBox.setText("l'offre n'est pas ajoute ");
                msgBox.exec();
        return false;
    }
}
bool offre::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM OFFRE WHERE NOM  ='"+ui->tableView_10->model()->data(ui->tableView_10->model()->index(ui->tableView_10->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("l'offre a ete supprime ");
                     msgBox.exec();
             return true;
         }
         else{
             QMessageBox msgBox ;
                     msgBox.setText("l'offre n'est pas supprime ");
                     msgBox.exec();
             return false;
}
}
void offre::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from OFFRE WHERE NOM ='"+ui->tableView_10->model()->data(ui->tableView_10->model()->index(ui->tableView_10->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_11->setText(q.value(1).toString());
    ui->lineEdit_45->setText(q.value(2).toString());
    ui->lineEdit_46->setText(q.value(3).toString());
    ui->lineEdit_47->setDate(q.value(4).toDate());
}
void offre::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select nom, id, date_offre,client_cible from OFFRE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_10->setModel(modal);
}



QSqlQueryModel *offre::trierOffre()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  nom, id, date_offre, client_cible from OFFRE order by nom");
   return model ;
}
QSqlQueryModel *offre::rechercherOffre(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from OFFRE where nom= '"+nom+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}
