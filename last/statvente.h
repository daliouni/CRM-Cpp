#ifndef STATVENTE_H
#define STATVENTE_H
#include <QVector>
#include "MainWindow.h"
#include "ui_mainwindow.h"

class statvente
{

public:
     statvente();
     QVector<double> Statistique();
     void makePlot();
private slots:
     void on_pushButton_49_clicked();



     void on_pushButton_14_clicked();

private :
     Ui::MainWindow *ui;
};

#endif // STATVENTE_H
