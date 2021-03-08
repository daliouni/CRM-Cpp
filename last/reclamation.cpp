#include "reclamation.h"

#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>



reclamation::reclamation()
{
num_reclamation ="";
sujet ="";
description="";


}
reclamation::reclamation(QString num_reclamation, QString sujet , QString description)
{
    this->num_reclamation=num_reclamation;
    this->sujet=sujet;
    this->description=description;
}
bool reclamation::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into RECLAMATION(num_reclamation, sujet, description) VALUES (:num_reclamation, :sujet, :description)");
        q.bindValue(":num_reclamation",ui->lineEdit_19->text());
        q.bindValue(":sujet",ui->lineEdit_20->text());
        q.bindValue(":description",ui->lineEdit_37->text());


        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la reclamation a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("la reclamation n'est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool reclamation::modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update RECLAMATION set  SUJET=:sujet,DESCRIPTION=:description where NUM_RECLAMATION=:num_reclamation" );
    q.bindValue(":num_reclamation",ui->lineEdit_19->text());
    q.bindValue(":sujet",ui->lineEdit_20->text());
    q.bindValue(":description",ui->lineEdit_37->text());
    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("la reclamation a ete modifiee ");
                msgBox.exec();
        return true;
    }
    else
{
        QMessageBox msgBox ;
                msgBox.setText("la reclamation n'est pas modifiee");
                msgBox.exec();
        return false;
    }
}
bool reclamation::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM RECLAMATION WHERE NUM_RECLAMATION ='"+ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             QMessageBox msgBox ;
                     msgBox.setText("la reclamation a ete supprime ");
                     msgBox.exec();
             return true;
         }
         else
{
             QMessageBox msgBox ;
                     msgBox.setText("la reclamation n'est pas supprime ");
                     msgBox.exec();
             return false;
         }

}
void reclamation::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from RECLAMATION WHERE NUM_RECLAMATION ='"+ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_19->setText(q.value(1).toString());
    ui->lineEdit_20->setText(q.value(2).toString());
    ui->lineEdit_37->setText(q.value(3).toString());
}
void reclamation::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select num_reclamation, sujet, description from RECLAMATION");
    q.exec();
    modal->setQuery(q);
    ui->tableView_7->setModel(modal);
}


