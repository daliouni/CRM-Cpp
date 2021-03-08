#include "smtp.h"
#include <QDebug>
#include "src/SmtpMime"
smtp::smtp(QString dest, QString nom, QString titre, QString contenue){
    this->destMail = dest;
    this->destNom = nom;
    this->mailTitre = titre;
    this->contenue = contenue;
}

void smtp::sendMail(){
    // This is a first demo application of the SmtpClient for Qt project

            // First we need to create an SmtpClient object
            // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

            SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

            // We need to set the username (your email address) and the password
            // for smtp authentification.

            smtp.setUser("qtcreator6@gmail.com");
            smtp.setPassword("123456789az");

            // Now we create a MimeMessage object. This will be the email.
            MimeMessage message;

            message.setSender(new EmailAddress("qtcreator6@gmail.com", "hi"));
            message.addRecipient(new EmailAddress(destMail,destNom));
            message.setSubject(mailTitre);

            // Now add some text to the email.
            // First we create a MimeText object.

            MimeText text;

            text.setText(contenue);

            // Now add it to the mail

            message.addPart(&text);

            // Now we can send the mail


            if (!smtp.connectToHost()) {
                qDebug() << "Failed to connect to host!" << endl;
              //  return -1;
            }

            if (!smtp.login()) {
                qDebug() << "Failed to login!" << endl;
                //return -2;
            }

            if (!smtp.sendMail(message)) {
                qDebug() << "Failed to send mail!" << endl;
                //return -3;
            }

            smtp.quit();

}


void smtp::sendMailwithpic(){
        // This is a first demo application of the SmtpClient for Qt project

                // First we need to create an SmtpClient object
                // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

                SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

                // We need to set the username (your email address) and the password
                // for smtp authentification.

                smtp.setUser("qtcreator6@gmail.com");
                smtp.setPassword("123456789az");

                // Now we create a MimeMessage object. This will be the email.
                MimeMessage message;

                message.setSender(new EmailAddress("qtcreator6@gmail.com", "hi"));
                message.addRecipient(new EmailAddress(destMail,destNom));
                message.setSubject(mailTitre);

                // Now add some text to the email.
                // First we create a MimeText object.

                MimeText text;

                text.setText(contenue);

                // Now add it to the mail

                message.addPart(&text);

                //MimeAttachment attachment (new QFile(File));
MimeAttachment attachment (new QFile("C:/Users/ASUS/Desktop/THINGS/PIC/25.png"));
                    // the file type can be setted. (by default is application/octet-stream)
                    attachment.setContentType("image/png");

                    // Now add it to message
                    message.addPart(&attachment);

                // Now we can send the mail


                if (!smtp.connectToHost()) {
                    qDebug() << "Failed to connect to host!" << endl;
                  //  return -1;
                }

                if (!smtp.login()) {
                    qDebug() << "Failed to login!" << endl;
                    //return -2;
                }

                if (!smtp.sendMail(message)) {
                    qDebug() << "Failed to send mail!" << endl;
                    //return -3;
                }

                smtp.quit();

    }
