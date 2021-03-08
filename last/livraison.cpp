#include "livraison.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include<QString>
#include<iostream>
#include <QMessageBox>


livraison::livraison()
{
    locatisation="";
    codefacture=0;
    codecommande=0;
    nom_prenom="";
    temps="";

}
livraison::livraison(QString localisation ,int codefacture,int codecommande,QString nom_prenom,QString temps)
{
this->locatisation=localisation;
this->codefacture=codefacture;
this->codecommande=codecommande;
this->nom_prenom=nom_prenom;
this->temps=temps;


}
bool livraison::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into LIVRAISON(localisation,codefacture,codecommande,nom_prenom,temps) VALUES (:localisation,:codefacture,:codecommande,:nom_prenom,:temps)");
        q.bindValue(":localisation",ui->lineEdit_31->text());
        q.bindValue(":codefacture",ui->lineEdit_32->text());
        q.bindValue(":codecommande",ui->lineEdit_33->text());
        q.bindValue(":nom_prenom",ui->lineEdit_34->text());
        q.bindValue(":temps",ui->lineEdit_35->text());

        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la livraison a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la livraison n'est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
void livraison::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from LIVRAISON WHERE CODEFACTURE ='"+ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_31->setText(q.value(1).toString());
    ui->lineEdit_32->setText(q.value(2).toString());
    ui->lineEdit_33->setText(q.value(3).toString());
    ui->lineEdit_34->setText(q.value(4).toString());
    ui->lineEdit_35->setText(q.value(5).toString());

}
void livraison::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select localisation,codefacture,codecommande,nom_prenom,temps from LIVRAISON");
    q.exec();
    modal->setQuery(q);
    ui->tableView_2->setModel(modal);
}
bool livraison::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

        q.prepare("DELETE FROM LIVRAISON WHERE LOCALISATION ='"+ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString()+"'");

         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la livraison a ete supprime ");
                     msgBox.exec();
              std::cout<< "Ça marche  ! :(" <<std::endl;
              return true;
         }
         else {

             QMessageBox msgBox ;
                     msgBox.setText("la livraison n'est pas supprime ");
                     msgBox.exec();
             std::cout<< "Ça marche pas ! :(" <<std::endl;

             return false;
         }

}

bool livraison::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update LIVRAISON set  CODEFACTURE=:codefacture,CODECOMMANDE=:codecommande,NOM_PRENOM=:nom_prenom , TEMPS=:temps where LOCALISATION=:localisation" );
    q.bindValue(":localisation",ui->lineEdit_31->text());
    q.bindValue(":codefacture",ui->lineEdit_32->text());
    q.bindValue(":codecommande",ui->lineEdit_33->text());
    q.bindValue(":nom_prenom",ui->lineEdit_34->text());
    q.bindValue(":temps",ui->lineEdit_35->text());
    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("la livraison a ete modifiee ");
                msgBox.exec();
        return  true;



    }
    else
{
        QMessageBox msgBox ;
    msgBox.setText("la livraison n'est pas modifiee ");
    msgBox.exec();
        return false;
    }
}


