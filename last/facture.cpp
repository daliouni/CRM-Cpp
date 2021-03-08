#include "facture.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include<QString>
#include<iostream>
#include <QMessageBox>


facture::facture()
{
code_facture="";
code_commande=0;
montant=0;
reglement="";
affaire="";



}
facture::facture(QString code_facture,int code_commande,int montant,QString reglement,QString affaire)
{
this->code_facture=code_facture;
this->code_commande=code_commande;
this->montant=montant;
this->reglement=reglement;
this->affaire=affaire;


}
bool facture::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into FACTURE(codefacture,codecommande,montant,reglement,affaire) VALUES (:codefacture,:codecommande,:montant,:reglement,:affaire)");
        q.bindValue(":codefacture",ui->lineEdit_27->text());
        q.bindValue(":codecommande",ui->lineEdit_28->text());
        q.bindValue(":montant",ui->lineEdit_30->text());
        q.bindValue(":reglement",ui->lineEdit_29->text());
        q.bindValue(":affaire",ui->lineEdit_36->text());

        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("le produit a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("le produit a ete ajoute ");
                    msgBox.exec();
                    return false;
        }
}
void facture::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from FACTURE WHERE CODEFACTURE ='"+ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_27->setText(q.value(1).toString());
    ui->lineEdit_28->setText(q.value(2).toString());
    ui->lineEdit_30->setText(q.value(3).toString());
    ui->lineEdit_29->setText(q.value(4).toString());
    ui->lineEdit_36->setText(q.value(5).toString());

}
void facture::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select codefacture,codecommande,montant,reglement,affaire from FACTURE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_4->setModel(modal);
}
bool facture::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

        q.prepare("DELETE FROM FACTURE WHERE CODEFACTURE ='"+ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),0)).toString()+"'");

         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la facture a ete supprime ");
                     msgBox.exec();
              std::cout<< "Ça marche  ! :(" <<std::endl;
              return true;
         }
         else {
             QMessageBox msgBox ;
                     msgBox.setText("la facture n'est pas supprimee ");
                     msgBox.exec();
             std::cout<< "Ça marche pas ! :(" <<std::endl;

             return false;
         }

}

bool facture::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update FACTURE set  CODECOMMANDE=:codecommande,MONTANT=:montant,REGLEMENT=:reglement,AFFAIRE=:affaire where CODEFACTURE=:codefacture" );
    q.bindValue(":codefacture",ui->lineEdit_27->text());
    q.bindValue(":codecommande",ui->lineEdit_28->text());
    q.bindValue(":montant",ui->lineEdit_30->text());
    q.bindValue(":reglement",ui->lineEdit_29->text());
    q.bindValue(":affaire",ui->lineEdit_36->text());
    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("la facture a ete modifiee ");
                msgBox.exec();
        return true;
    }
    else {
        QMessageBox msgBox ;
                msgBox.setText("la facture n'est pas modifiee");
                msgBox.exec();
        return false;
    }
}

QSqlQueryModel *facture::trierFacture()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  codefacture,codecommande, montant,reglement,affaire from FACTURE order by codefacture");
   return model ;
}
QSqlQueryModel *facture::rechercherFacture(QString code_facture)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from FACTURE where codefacture= '"+code_facture+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}

