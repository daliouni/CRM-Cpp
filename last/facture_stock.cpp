#include "facture_stock.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <QMessageBox>

facture_stock::facture_stock()
{
id_fournisseur=0;
reference_produit="";
description="";
quantite=0;
prix_unitaire=0;
taxe_devente=0;
}
facture_stock::facture_stock(int id_fournisseur,QString reference_produit,QString description,int quantite,int prix_unitaire,int taxe_devente)
{
    this->id_fournisseur=id_fournisseur;
    this->reference_produit=reference_produit;
    this->description=description;
    this->quantite=quantite;
    this->prix_unitaire=prix_unitaire;
    this->taxe_devente=taxe_devente;

}
bool facture_stock::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into FACTURE_STOCK(id_fournisseur, reference_produit, description,quantite,prix_unitaire,taxe_devente) VALUES (:id_fournisseur, :reference_produit, :description,:quantite ,:prix_unitaire,:taxe_devente)");
        q.bindValue(":id_fournisseur",ui->lineEdit_39->text());
        q.bindValue(":reference_produit",ui->lineEdit_40->text());
        q.bindValue(":description",ui->lineEdit_41->text());
        q.bindValue(":quantite",ui->lineEdit_42->text());
        q.bindValue(":prix_unitaire",ui->lineEdit_43->text());
        q.bindValue(":taxe_devente",ui->lineEdit_44->text());


        if (    q.exec())
        {
            QMessageBox msgBox ;
                    msgBox.setText("le produit a ete ajoute ");
                    msgBox.exec();
         std::cout << "Ça marche ! 🙂" << std::endl;
           return true ;
        }
        else
        {
            QMessageBox msgBox ;
                    msgBox.setText("le produit n'est pas  ajoute ");
                    msgBox.exec();
            std::cout<< "Ça marche pas ! :(" <<std::endl;
          return false;
        }
}
bool facture_stock::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update FACTURE_STOCK set  REFERENCE_PRODUIT=:reference_produit,DESCRIPTION=:description,QUANTITE=:quantite,PRIX_UNITAIRE=:prix_unitaire,TAXE_DEVENTE=:taxe_devente where ID_FOURNISSEUR=:id_fournisseur" );
    q.bindValue(":id_fournisseur",ui->lineEdit_39->text());
    q.bindValue(":reference_produit",ui->lineEdit_40->text());
    q.bindValue(":description",ui->lineEdit_41->text());
    q.bindValue(":quantite",ui->lineEdit_42->text());
    q.bindValue(":prix_unitaire",ui->lineEdit_43->text());
    q.bindValue(":taxe_devente",ui->lineEdit_44->text());

    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("le produit a ete modifie ");
                msgBox.exec();
        return true;
    }
    else
{
        QMessageBox msgBox ;
                msgBox.setText("le produit n'est pas modifie ");
                msgBox.exec();
        return false;
    }
}
bool facture_stock::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM FACTURE_STOCK WHERE ID_FOURNISSEUR ='"+ui->tableView_9->model()->data(ui->tableView_9->model()->index(ui->tableView_9->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("le produit a ete supprime ");
                     msgBox.exec();
             return true;
         }
         else
         {
             QMessageBox msgBox ;
                     msgBox.setText("le produit n'est pas supprime ");
                     msgBox.exec();
             return false;
         }

}
void facture_stock::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from FACTURE_STOCK WHERE ID_FOURNISSEUR ='"+ui->tableView_9->model()->data(ui->tableView_9->model()->index(ui->tableView_9->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_39->setText(q.value(1).toString());
    ui->lineEdit_40->setText(q.value(2).toString());
    ui->lineEdit_41->setText(q.value(3).toString());
    ui->lineEdit_42->setText(q.value(4).toString());
    ui->lineEdit_43->setText(q.value(5).toString());
    ui->lineEdit_44->setText(q.value(6).toString());


}
void facture_stock::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select id_fournisseur, reference_produit, description, quantite, prix_unitaire, taxe_devente from FACTURE_STOCK");
    q.exec();
    modal->setQuery(q);
    ui->tableView_9->setModel(modal);
}


