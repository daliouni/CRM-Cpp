#include "demande.h"
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>



demande::demande()
{
num_demande ="";
sujet ="";
description="";


}
demande::demande(QString num_demande, QString sujet , QString description)
{
    this->num_demande=num_demande;
    this->sujet=sujet;
    this->description=description;
}
bool demande::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into DEMANDE(num_demande, sujet, description) VALUES (:num_demande, :sujet, :description)");
        q.bindValue(":num_demande",ui->lineEdit_17->text());
        q.bindValue(":sujet",ui->lineEdit_18->text());
        q.bindValue(":description",ui->lineEdit_10->text());


        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la demande a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la demande n'est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool demande::modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update DEMANDE set  SUJET=:sujet,DESCRIPTION=:description where NUM_DEMANDE=:num_demande" );
    q.bindValue(":num_demande",ui->lineEdit_17->text());
    q.bindValue(":sujet",ui->lineEdit_18->text());
    q.bindValue(":description",ui->lineEdit_10->text());
    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("la demande a ete modifiee ");
                msgBox.exec();
        return true;
    }
    else
{
        QMessageBox msgBox ;
                msgBox.setText("la demande n'est pas modifier ");
                msgBox.exec();
        return false;
    }
}
bool demande::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM DEMANDE WHERE NUM_DEMANDE ='"+ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             return true;
         }
         else return false;

}
void demande::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from DEMANDE WHERE NUM_DEMANDE ='"+ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_17->setText(q.value(1).toString());
    ui->lineEdit_18->setText(q.value(2).toString());
    ui->lineEdit_10->setText(q.value(3).toString());
}
void demande::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select num_demande, sujet, description from DEMANDE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_6->setModel(modal);
}


