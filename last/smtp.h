#ifndef SMTP_H
#define SMTP_H
#include <QString>
class smtp{
private:
    QString destMail;
    QString destNom;
    QString mailTitre;
    QString contenue;
    QString File;
public:
    smtp(){}
    smtp(QString, QString, QString, QString);
    void setDestMail(QString mail){this->destMail = mail;}
    void setDestNom(QString nom){this->destNom = nom;}
    void setMailTitre(QString titre){this->mailTitre = titre;}
    void setContenue(QString contenue){this->contenue = contenue;}
    void setFile(QString File){this->File = File;}
    QString getDestMail(){return destMail;}
    void sendMail();
    void sendMailwithpic();
};

#endif // SMTP_H
