#include "evenement.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include <iostream>
#include <QMessageBox>

evenement::evenement()
{
    id="";
    nom_event="";
    date_event="";
    lieu="";
    budget=0;


}
evenement::evenement(QString id,QString nom_event,QString date_event,QString lieu,int budget)
{
    this->id=id;
    this->nom_event=nom_event;
    this->date_event=date_event;
    this->lieu=lieu;
    this->budget=budget;

}
bool evenement::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;


        q.prepare("INSERT into EVENEMENT(id,nom_event ,date_event,lieu,budget) VALUES (:id, :nom_event, :date_event,:lieu,:budget)");
        q.bindValue(":id",ui->lineEdit_144->text());
        q.bindValue(":nom_event",ui->lineEdit_143->text());
        q.bindValue(":date_event",ui->lineEdit_142->text());
        q.bindValue(":lieu",ui->lineEdit_145->text());
        q.bindValue(":budget",ui->lineEdit_146->text());
        if (    q.exec())
        {
            std::cout << "Ça marche ! 🙂" << std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("l'evenement a ete ajoute ");
                    msgBox.exec();
            return true ;
        }
        else
        {
            std::cout<< "Ça marche pas ! :(" <<std::endl;

            QMessageBox msgBox ;
                    msgBox.setText("l'evenement  n'est pas ajoute ");
                    msgBox.exec();
                    return false;
        }
}
bool evenement::Modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update EVENEMENT set ID=:id,DATE_EVENT=:date_event ,LIEU=:lieu , BUDGET=:budget where  NOM_EVENT=:nom_event" );
    q.bindValue(":id",ui->lineEdit_144->text());
    q.bindValue(":nom_event",ui->lineEdit_143->text());
    q.bindValue(":date_event",ui->lineEdit_142->text());
    q.bindValue(":lieu",ui->lineEdit_145->text());
    q.bindValue(":budget",ui->lineEdit_146->text());
    if(q.exec())
    {
        QMessageBox msgBox ;
                msgBox.setText("l'evenement a ete modifiee ");
                msgBox.exec();
        return true;
    }
    else
    {QMessageBox msgBox ;
                msgBox.setText("l'evenement n'est pas modifiee ");
                msgBox.exec();
        return false;
    }
}
bool evenement::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM EVENEMENT WHERE NOM_EVENT  ='"+ui->tableView_31->model()->data(ui->tableView_31->model()->index(ui->tableView_31->selectionModel()->currentIndex().row(),1)).toString()+"'");


         if(q.exec())
         {

             QMessageBox msgBox ;
                     msgBox.setText("l'evenement a ete supprimee ");
                     msgBox.exec();
             return true;
         }
         else
            { QMessageBox msgBox ;
                     msgBox.setText("l'evenement n'est pas supprimee ");
                     msgBox.exec();
             return false;
         }

}
void evenement::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from EVENEMENT WHERE NOM_EVENT ='"+ui->tableView_31->model()->data(ui->tableView_31->model()->index(ui->tableView_31->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_144->setText(q.value(1).toString());
    ui->lineEdit_143->setText(q.value(2).toString());
    ui->lineEdit_142->setDate(q.value(3).toDate());
    ui->lineEdit_145->setText(q.value(4).toString());
    ui->lineEdit_146->setText(q.value(4).toString());
}
void evenement::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select id, nom_event, date_event,lieu,budget from EVENEMENT");
    q.exec();
    modal->setQuery(q);
    ui->tableView_31->setModel(modal);
}


QSqlQueryModel *evenement::trierEvent()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  id, nom_event, date_event,lieu,budget from EVENEMENT order by nom_event");
   return model ;
}
QSqlQueryModel *evenement::rechercherEvent(QString nom_event)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from EVENEMENT where nom_event= '"+nom_event+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}
