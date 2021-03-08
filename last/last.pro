#-------------------------------------------------
#
# Project created by QtCreator 2017-12-09T21:13:25
#
#-------------------------------------------------

QT       += core gui sql printsupport positioning


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = last
TEMPLATE = app

# Location of SMTP Library
SMTP_LIBRARY_LOCATION ="C:/Users/DALI/Documents/last/build-SMTPEmail-Desktop_Qt_5_9_2_MinGW_32bit-Debug"
win32:CONFIG(release, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/debug/ -lSMTPEmail
else:unix: LIBS += -L$$SMTP_LIBRARY_LOCATION -lSMTPEmail

INCLUDEPATH += $$SMTP_LIBRARY_LOCATION
DEPENDPATH += $$SMTP_LIBRARY_LOCATION

SOURCES += main.cpp\
        mainwindow.cpp \
    commande.cpp \
    facture.cpp \
    geolocalisation.cpp \
    livraison.cpp \
    qcustomplot.cpp \
    client.cpp \
    demande.cpp \
    reclamation.cpp \
    stock.cpp \
    facture_stock.cpp \
    offre.cpp \
    evenement.cpp \
    smtp.cpp \
    rdv.cpp \
    liv.cpp

HEADERS  += mainwindow.h \
    commande.h \
    facture.h \
    geolocalisation.h \
    livraison.h \
    qcustomplot.h \
    client.h \
    demande.h \
    reclamation.h \
    stock.h \
    facture_stock.h \
    offre.h \
    evenement.h \
    smtp.h \
    rdv.h \
    liv.h

FORMS    += mainwindow.ui

DISTFILES +=
