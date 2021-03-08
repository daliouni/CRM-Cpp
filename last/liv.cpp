#include "liv.h".h"

liv::liv()
{
   nom_livraison="";
   objet_livraison="";
    quantite_livraison="";

       date_livraison="";
    adresse_livraison="";
}
liv::liv(QString nom_livraison,QString objet_livraison,QString quantite_livraison,QString date_livraison, QString adresse_livraison)

{   this->nom_livraison=nom_livraison;
    this->objet_livraison=objet_livraison;
    this->quantite_livraison=quantite_livraison;
    this->date_livraison=date_livraison;
    this->adresse_livraison=adresse_livraison;

}
bool liv::ajouter()
{

    QSqlQuery query;
                     query.prepare("INSERT INTO LIV VALUES (?,?,?,?,?)");
                     query.addBindValue(this->nom_livraison);
                     query.addBindValue(this->objet_livraison);
                     query.addBindValue(this->quantite_livraison);
                     query.addBindValue(this->date_livraison);
                     query.addBindValue(this->adresse_livraison);

       return query.exec();

}
bool liv :: supprimer(QString objet_livraison)
{
    QSqlQuery qry ;
    qry.prepare("delete from LIV where OBJET_LIVRAISON=?");
    qry.addBindValue(objet_livraison);
    return qry.exec();

}
QSqlQueryModel* liv ::affichage(QString dd)
{

      QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from LIV where DATE_LIVRAISON='"+dd+"'");  //parcours table
        qr->addBindValue(dd);
       qr->exec();
       modal->setQuery(*qr);
           return modal;


}
QSqlQueryModel* liv ::affichagetout()
{

      QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery *qr=new QSqlQuery();
        qr->prepare("SELECT * from LIV ");  //parcours table
       qr->exec();
       modal->setQuery(*qr);
           return modal;


}

    bool liv::modifier(QString a,QString b,QString c,QString d, QString e)
    {
     QSqlQuery q;
    //Mettre à jour le nom

     q.prepare("UPDATE LIV set NOM_LIVRAISON=:NOM_LIVRAISON,QUANTITE_LIVRAISON=:QUANTITE_LIVRAISON, DATE_LIVRAISON=:DATE_LIVRAISON,ADRESSE_LIVRAISON=:ADRESSE_LIVRAISON where OBJET_LIVRAISON='"+a+"'");
            q.bindValue(":NOM_LIVRAISON",e);
            q.bindValue(":QUANTITE_LIVRAISON",b);
            q.bindValue(":DATE_LIVRAISON",d);
            q.bindValue(":ADRESSE_LIVRAISON",c);
            return q.exec();




}

            QSqlQueryModel* liv::recherche ( QString b)
            {
                QSqlQueryModel * modal=new QSqlQueryModel();
                        QSqlQuery *qr=new QSqlQuery();
                        qr->prepare("SELECT * from LIV where NOM_LIVRAISON LIKE '%"+b+"%' or OBJET_LIVRAISON LIKE'%"+b+"%' or QUANTITE_LIVRAISON LIKE '%"+b+"%' or DATE_LIVRAISON LIKE'"+b+"' or ADRESSE_LIVRAISON LIKE'"+b+"'");  //parcours table
                        qr->exec();
                        modal->setQuery(*qr);
                        return modal;
            }
