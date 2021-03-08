#include "client.h"
#include <QMessageBox>
#include <QString>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <utility>




Client::Client()
{
    CIN=" ";
    Nom=" ";
    Prenom=" ";
    Age=" ";
    Adresse=" ";
    Email=" ";
    Tel=" ";
    Category ="";
    Sexe ="";
}

Client::Client(QString CIN,QString Nom,QString Prenom,QString Age,QString Adresse,QString Email,QString Tel,QString Category,QString Sexe)
{
    this->CIN=CIN;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Age=Age;
    this->Adresse=Adresse;
    this->Email=Email;
    this->Tel=Tel;
    this->Category=Category;
    this->Sexe=Sexe;

}

bool Client::ajouter(Ui::MainWindow*ui)
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT(ID_CLIENT,NOM,PRENOM,AGE,ADRESSE,EMAIL,TEL,CATEGORIE,SEXE)values(:id_client,:nom,:prenom,:age,:adresse,:email,:tel,:categorie,:sexe)");
    query.bindValue(":id_client",ui->lineEdit_3->text());
    query.bindValue(":nom",ui->lineEdit_4->text());
    query.bindValue(":prenom",ui->lineEdit_5->text());
    query.bindValue(":age",ui->lineEdit_6->text());
    query.bindValue(":adresse",ui->lineEdit_7->text());
    query.bindValue(":email",ui->lineEdit_8->text());
    query.bindValue(":tel",ui->lineEdit_9->text());
    query.bindValue(":categorie",ui->comboBox->currentText());
    query.bindValue(":sexe",ui->comboBox_2->currentText());

    if(query.exec())

       { QMessageBox msgBox ;
                msgBox.setText("le client a ete ajoute ");
                msgBox.exec();
        return true;
    }
    else

{
        QMessageBox msgBox ;
                msgBox.setText("le client n'est pas ajoute ");
                msgBox.exec();
        return false;
    }
}

bool Client::modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("update CLIENT set NOM=:nom,PRENOM=:prenom,AGE=:age,ADRESSE=:adresse,EMAIL=:email,TEL=:tel,CATEGORIE=:categorie,SEXE=:sexe where ID_CLIENT=:id_client" );
    q.bindValue(":id_client",ui->lineEdit_3->text());
    q.bindValue(":nom",ui->lineEdit_4->text());
    q.bindValue(":prenom",ui->lineEdit_5->text());
    q.bindValue(":age",ui->lineEdit_6->text());
    q.bindValue(":adresse",ui->lineEdit_7->text());
    q.bindValue(":email",ui->lineEdit_8->text());
    q.bindValue(":adresse",ui->lineEdit_9->text());
    q.bindValue(":categorie",ui->comboBox->currentText());
    q.bindValue(":sexe",ui->comboBox_2->currentText());


    if(q.exec())
    {

        QMessageBox msgBox ;
                msgBox.setText("le client a ete modifie ");
                msgBox.exec();
        return true;
    }
    else
{
        QMessageBox msgBox ;
                msgBox.setText("le client n'est pas modifie ");
                msgBox.exec();
        return false;
}
}

bool Client::supprimer(Ui::MainWindow *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM CLIENT WHERE ID_CLIENT ='"+ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {

             QMessageBox msgBox ;
                     msgBox.setText("le client a ete supprime ");
                     msgBox.exec();
             return true;

         }
         else
{
             QMessageBox msgBox ;
                     msgBox.setText("le client n'est pas supprime ");
                     msgBox.exec();
             return false;
         }

}
void Client::Afficher(Ui::MainWindow *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from CLIENT WHERE ID_CLIENT ='"+ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();
    ui->lineEdit_3->setText(q.value(1).toString());
    ui->lineEdit_4->setText(q.value(2).toString());
    ui->lineEdit_5->setText(q.value(3).toString());
    ui->lineEdit_6->setText(q.value(4).toString());
    ui->lineEdit_7->setText(q.value(5).toString());
    ui->lineEdit_8->setText(q.value(6).toString());
    ui->lineEdit_9->setText(q.value(7).toString());



}
void Client::AfficherTable(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select id_client, nom,prenom, age,adresse,email,tel from CLIENT");
    q.exec();
    modal->setQuery(q);
    ui->tableView_5->setModel(modal);
}

QSqlQueryModel *Client::trierClient()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  id_client,nom,prenom,age,adresse,email,tel,categorie,sexe from CLIENT order by nom");
   return model ;
}
QSqlQueryModel *Client::rechercherClient(QString Nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from CLIENT where nom= '"+Nom+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}
