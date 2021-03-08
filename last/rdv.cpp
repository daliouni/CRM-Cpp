#include "rdv.h"

rdv::rdv()
{
    nom_client="";
   prenom_client="";
     adresse_client="";
        sexe_client="";
       code_rdv="";
    date_rdv="";
}
rdv::rdv(QString nom_client,QString prenom_client,QString adresse_client,QString sexe_client, QString code_rdv, QString date_rdv)

{   this->nom_client=nom_client;
    this->prenom_client=prenom_client;
    this->adresse_client=adresse_client;
    this->sexe_client=sexe_client;
    this->code_rdv=code_rdv;
    this->date_rdv=date_rdv;

}
bool rdv::ajouter()
{

    QSqlQuery query;
                     query.prepare("INSERT INTO RDV VALUES (?,?,?,?,?,?)");
                     query.addBindValue(this->nom_client);
                     query.addBindValue(this->prenom_client);
                     query.addBindValue(this->adresse_client);
                     query.addBindValue(this->sexe_client);
                     query.addBindValue(this->code_rdv);
                     query.addBindValue(this->date_rdv);

       return query.exec();

}
bool rdv :: supprimer(QString code_rdv)
{
    QSqlQuery qry ;
    qry.prepare("delete from RDV where CODE_RDV=?");
    qry.addBindValue(code_rdv);
    return qry.exec();

}
QSqlQueryModel* rdv ::affichage(QString dd)
{

      QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from RDV where DATE_RDV='"+dd+"'");  //parcours table
        qr->addBindValue(dd);
       qr->exec();
       modal->setQuery(*qr);
           return modal;


}
QSqlQueryModel* rdv ::affichagetout()
{

      QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from RDV ");  //parcours table
       qr->exec();
       modal->setQuery(*qr);
           return modal;


}

    bool rdv::modifier(QString a,QString b,QString c,QString d, QString e, QString f)
    {
     QSqlQuery q;
    //Mettre à jour le nom

     q.prepare("UPDATE RDV set NOM_CLIENT=:NOM_CLIENT, PRENOM_CLIENT=:PRENOM_CLIENT,ADRESSE_CLIENT=:ADRESSE_CLIENT, SEXE_CLIENT=:SEXE_CLIENT,DATE_RDV=:DATE_RDV where CODE_RDV='"+a+"'");
            q.bindValue(":NOM_CLIENT",e);
            q.bindValue(":PRENOM_CLIENT",b);
            q.bindValue(":SEXE_CLIENT",d);
            q.bindValue(":ADRESSE_CLIENT",c);
            q.bindValue(":DATE_RDV",f);
            return q.exec();




}

            QSqlQueryModel* rdv::recherche ( QString b)
            {
                QSqlQueryModel * modal=new QSqlQueryModel();
                        QSqlQuery *qr=new QSqlQuery();
                        qr->prepare("SELECT * from RDV where NOM_CLIENT LIKE '%"+b+"%' or PRENOM_CLIENT LIKE'%"+b+"%' or SEXE_CLIENT LIKE '%"+b+"%' or CODE_RDV LIKE'"+b+"' or DATE_RDV LIKE'"+b+"' or ADRESSE_CLIENT LIKE'"+b+"'");  //parcours table
                        qr->exec();
                        modal->setQuery(*qr);
                        return modal;
            }
