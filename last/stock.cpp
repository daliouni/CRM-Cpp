#include "stock.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>


stock::stock()
{
    code_produit=0;
    reference="";
    fournisseur="";
    prix=0;
    remise=0;
    stock_produit="";

}
stock::stock(int code_produit, QString reference, QString fournisseur, int prix, int remise, QString stock_produit)
{
    this->code_produit=code_produit;
    this->reference=reference;
    this->fournisseur=fournisseur;
    this->prix=prix;
    this->remise=remise;
    this->stock_produit=stock_produit;

}
bool stock::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into STOCK(code_produit, reference, fournisseur,prix,remise,stock_produit) VALUES (:code_produit, :reference, :fournisseur,:prix ,:remise,:stock_produit)");
        q.bindValue(":code_produit",ui->lineEdit_12->text());
        q.bindValue(":reference",ui->lineEdit_13->text());
        q.bindValue(":fournisseur",ui->lineEdit_14->text());
        q.bindValue(":prix",ui->lineEdit_15->text());
        q.bindValue(":remise",ui->lineEdit_26->text());
        q.bindValue(":stock_produit",ui->lineEdit_38->text());


        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("le stock a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("le stock n'est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool stock::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update STOCK set  REFERENCE=:reference,FOURNISSEUR=:fournisseur,PRIX=:prix,REMISE=:remise,STOCK_PRODUIT=:stock_produit where CODE_PRODUIT=:code_produit" );
    q.bindValue(":code_produit",ui->lineEdit_12->text());
    q.bindValue(":reference",ui->lineEdit_13->text());
    q.bindValue(":forunisseur",ui->lineEdit_14->text());
    q.bindValue(":prix",ui->lineEdit_15->text());
    q.bindValue(":remise",ui->lineEdit_16->text());
    q.bindValue(":stock_produit",ui->lineEdit_38->text());

    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("le stock a ete ajoute ");
                msgBox.exec();
        return true;
    }
    else

{
        QMessageBox msgBox ;
                msgBox.setText("le stock n'est pas ajoute ");
                msgBox.exec();
                return false;
    }
}
bool stock::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM STOCK WHERE CODE_PRODUIT ='"+ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("le stock a ete supprime ");
                     msgBox.exec();
             return true;
         }
         else
 {
             QMessageBox msgBox ;
                     msgBox.setText("le stock n'est pas supprime ");
                     msgBox.exec();
                     return false;
         }

}
void stock::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from STOCK WHERE CODE_PRODUIT ='"+ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_12->setText(q.value(1).toString());
    ui->lineEdit_13->setText(q.value(2).toString());
    ui->lineEdit_14->setText(q.value(3).toString());
    ui->lineEdit_15->setText(q.value(4).toString());
    ui->lineEdit_16->setText(q.value(5).toString());
    ui->lineEdit_38->setText(q.value(6).toString());


}
void stock::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select code_produit, reference, fournisseur, prix, remise, stock_produit from STOCK");
    q.exec();
    modal->setQuery(q);
    ui->tableView_8->setModel(modal);
}
QSqlQueryModel *stock::trierStock()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  code_produit, reference, fournisseur, prix, remise, stock_produit from STOCK order by code_produit");
   return model ;
}
QSqlQueryModel *stock::rechercherStock(QString code_produit)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from STOCK where code_produit= '"+code_produit+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}
