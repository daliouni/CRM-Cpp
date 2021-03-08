#include "commande.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>
commande::commande()
{
    code_commande=0;
    nom_prenom="";
    nom_produit="";
    quantite=0;
    prix=0;

}
commande::commande(int code_commande,QString nom_prenom,QString nom_produit,int quantite,int prix)
{
    this->code_commande=code_commande;
    this->nom_prenom=nom_prenom;
    this->nom_produit=nom_produit;
    this->prix=prix;
    this->quantite=quantite;
}
bool commande::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into COMMANDE(codecommande, nom_prenom, Nom_produit,quantite,prix) VALUES (:codecommande, :nom_prenom, :nom_produit,:quantite,:prix)");
        q.bindValue(":codecommande",ui->lineEdit_22->text());
        q.bindValue(":nom_prenom",ui->lineEdit_23->text());
        q.bindValue(":nom_produit",ui->lineEdit_24->text());
        q.bindValue(":quantite",ui->lineEdit_25->text());
        q.bindValue(":prix",ui->lineEdit_26->text());

        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la commande a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la commande a ete ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool commande::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update COMMANDE set  NOM_PRENOM=:nom_prenom,NOM_PRODUIT=:nom_produit,QUANTITE=:quantite,PRIX=:prix where CODECOMMANDE=:codecommande" );
    q.bindValue(":codecommande",ui->lineEdit_22->text());
    q.bindValue(":nom_prenom",ui->lineEdit_23->text());
    q.bindValue(":nom_produit",ui->lineEdit_24->text());
    q.bindValue(":quantite",ui->lineEdit_25->text());
    q.bindValue(":prix",ui->lineEdit_26->text());
    if(q.exec())
    {
        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la commande a ete modifie ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la commande n'est pas modifiee ");
                    msgBox.exec();
                    return false;
        }
}
}
bool commande::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM COMMANDE WHERE CODECOMMANDE ='"+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la commande a ete supprimee ");
                     msgBox.exec();
             return true;
         }
         else

{
             QMessageBox msgBox ;
                     msgBox.setText("la commande n'est pas supprimee' ");
                     msgBox.exec();
             return false;
}
}

void commande::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from COMMANDE WHERE CODECOMMANDE ='"+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_22->setText(q.value(1).toString());
    ui->lineEdit_23->setText(q.value(2).toString());
    ui->lineEdit_24->setText(q.value(3).toString());
    ui->lineEdit_25->setText(q.value(4).toString());
    ui->lineEdit_26->setText(q.value(5).toString());

}
void commande::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select codecommande, nom_prenom, Nom_produit,quantite,prix from COMMANDE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_3->setModel(modal);
}
void commande::Tri_Prix(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from COMMANDE order by PRIX");
    q.exec();
    model->setQuery(q);
    ui->tableView_3->setModel(model);
}


QSqlQueryModel *commande::trierCommande()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  codecommande,nom_prenom, nom_produit,quantite,prix from COMMANDE order by codecommande");
   return model ;
}
QSqlQueryModel *commande::rechercherCommande(QString code_commande)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from COMMANDE where codecommande= '"+code_commande+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}
