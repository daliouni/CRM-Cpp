#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "facture.h"
#include "livraison.h"
#include "client.h"
#include <QSqlQuery>
#include<QMessageBox>
#include "qcustomplot.h"
#include "geolocalisation.h"
#include "demande.h"
#include"reclamation.h"
#include <QtPrintSupport>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include"notification.h"
#include "stock.h"
#include "facture_stock.h"
#include "evenement.h"
#include "src/SmtpMime"
#include "smtp.h"
#include "offre.h"
#include "rdv.h"
#include "liv.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{
      ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_5_clicked()
{
      ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_31_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_27_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_28_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_30_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
     ui->tableView_5->setSelectionBehavior(QAbstractItemView::SelectRows);

     Client c;
     c.AfficherTable(ui);

}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tableView_6->setSelectionBehavior(QAbstractItemView::SelectRows);
    demande D ;
    D.AfficherTable(ui);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    MainWindow::makePlot_client();


}


void MainWindow::on_pushButton_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
         ui->tableView_3->setSelectionBehavior(QAbstractItemView::SelectRows);
         commande C ;
         C.AfficherTable(ui);

}

void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
         ui->tableView_4->setSelectionBehavior(QAbstractItemView::SelectRows);
        facture F ;
         F.AfficherTable(ui);

}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(14);
     ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    livraison L ;
     L.AfficherTable(ui);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(15);
    MainWindow::makePlot_vente();

}
void MainWindow::on_pushButton_49_clicked()
{    MainWindow::makePlot_vente();
}

void MainWindow::on_pushButton_32_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_33_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_34_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_37_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_38_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_39_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_112_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_106_clicked()
{
    livraison l;
    l.ajouter(ui);
    l.AfficherTable(ui);
}

void MainWindow::on_pushButton_100_clicked()
{
    commande c;
    c.ajouter(ui);
    c.AfficherTable(ui);
}

void MainWindow::on_pushButton_101_clicked()
{
    if  (ui->tableView_3->selectionModel()->hasSelection())
        {
         commande C;


         C.supprimer(ui);
        C.AfficherTable(ui);
        }
}

void MainWindow::on_pushButton_102_clicked()
{
    commande C;
    C.Modifier(ui);
    C.AfficherTable(ui);
}

void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    ui->lineEdit_22->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_23->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_24->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),2)).toString());
        ui->lineEdit_25->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),3)).toString());
        ui->lineEdit_26->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->selectionModel()->currentIndex().row(),4)).toString());

}

void MainWindow::on_pushButton_103_clicked()
{
    facture f;
    f.ajouter(ui);
    f.AfficherTable(ui);
}

void MainWindow::on_pushButton_104_clicked()
{
    if  (ui->tableView_4->selectionModel()->hasSelection())
        {
         facture F;


         F.supprimer(ui);
        F.AfficherTable(ui);
        }

}

void MainWindow::on_pushButton_105_clicked()
{
    facture F;
    F.Modifier(ui);
    F.AfficherTable(ui);


}

void MainWindow::on_tableView_4_clicked(const QModelIndex &index)
{
    ui->lineEdit_27->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_28->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_30->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),2)).toString());
        ui->lineEdit_29->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),3)).toString());
        ui->lineEdit_36->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->selectionModel()->currentIndex().row(),4)).toString());



}

void MainWindow::on_pushButton_120_clicked()
{
    QSqlQuery q;
       q.prepare("select * from COMMANDE where CODECOMMANDE='"+ui->lineEdit_28->text()+"'");
       q.exec();
       q.next();
       ui->lineEdit_30->setText(q.value(4).toString());
       ui->lineEdit_29->setText(q.value(2).toString());

}

void MainWindow::on_pushButton_107_clicked()
{
    if  (ui->tableView_2->selectionModel()->hasSelection())
        {
         livraison L;


         L.supprimer(ui);
         L.AfficherTable(ui);
        }

}

void MainWindow::on_pushButton_108_clicked()
{
    livraison L;
    L.Modifier(ui);
    L.AfficherTable(ui);
}
void MainWindow::on_pushButton_51_clicked()
{ GPS g;
    g.search(ui->lineEdit_31->text());}
void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->lineEdit_31->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_32->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_33->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),2)).toString());
        ui->lineEdit_34->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),3)).toString());
        ui->lineEdit_35->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),4)).toString());


}
QVector<double> MainWindow::Statistique_vente()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT PRIX FROM COMMANDE WHERE PRIX<=200");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT PRIX FROM COMMANDE WHERE 200<PRIX and PRIX<=400");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT PRIX FROM COMMANDE WHERE 400<PRIX and PRIX<=600");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT PRIX FROM COMMANDE WHERE 600<PRIX and PRIX<=800");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT PRIX FROM COMMANDE WHERE 800<PRIX ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void MainWindow::makePlot_vente()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_vente());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"0-200"<<"200-400"<<"400-600"<<"600-800"<<"800-1000";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}
void MainWindow::on_pushButton_40_clicked()
{
    Client c ;
    c.ajouter(ui);
    c.AfficherTable(ui);
}
void MainWindow::on_pushButton_42_clicked()
{
    Client c ;
    c.modifier(ui);
    c.AfficherTable(ui);
}
void MainWindow::on_pushButton_41_clicked()
{
    if  (ui->tableView_5->selectionModel()->hasSelection())
        {
          Client c;


         c.supprimer(ui);
        c.AfficherTable(ui);
        }

}
void MainWindow::on_tableView_5_clicked(const QModelIndex &index)
{
        ui->lineEdit_3->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_4->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_5->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),2)).toString());
        ui->lineEdit_6->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),3)).toString());
        ui->lineEdit_7->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),4)).toString());
        ui->lineEdit_8->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),5)).toString());
        ui->lineEdit_9->setText(ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->selectionModel()->currentIndex().row(),6)).toString());

}
void MainWindow::on_pushButton_43_clicked()
{
    demande d ;
    d.ajouter(ui);
    d.AfficherTable(ui);
}
void MainWindow::on_pushButton_45_clicked()
{
    demande d ;
d.modifier(ui) ;
d.AfficherTable(ui);
}
void MainWindow::on_pushButton_44_clicked()
{
    if  (ui->tableView_6->selectionModel()->hasSelection())
        {
demande d;


         d.supprimer(ui);
        d.AfficherTable(ui);
        }

}
void MainWindow::on_tableView_6_clicked(const QModelIndex &index)
{
        ui->lineEdit_17->setText(ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_18->setText(ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_10->setText(ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),2)).toString());

}
void MainWindow::on_pushButton_46_clicked()
{
    reclamation r ;
    r.ajouter(ui);
    r.AfficherTable(ui);
}
void MainWindow::on_pushButton_48_clicked()
{
reclamation r;
        r.modifier(ui) ;
r.AfficherTable(ui);
}
void MainWindow::on_pushButton_47_clicked()
{
    if  (ui->tableView_7->selectionModel()->hasSelection())
        {
reclamation r;

         r.supprimer(ui);
        r.AfficherTable(ui);
        }

}
void MainWindow::on_tableView_7_clicked(const QModelIndex &index)
{
        ui->lineEdit_19->setText(ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),0)).toString());
        ui->lineEdit_20->setText(ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),1)).toString());
        ui->lineEdit_37->setText(ui->tableView_7->model()->data(ui->tableView_7->model()->index(ui->tableView_7->selectionModel()->currentIndex().row(),2)).toString());

}





QVector<double> MainWindow::Statistique_client()
{
    QSqlQuery q;
    QVector<double> stat(2);
    stat[0]=0;
    stat[1]=0;

    q.prepare("SELECT SEXE FROM CLIENT WHERE SEXE='Femme'");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT SEXE FROM CLIENT WHERE SEXE='Homme'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }

    return stat;
}
void MainWindow::makePlot_client()
{
    // prepare data:
    QVector<double> x3(2), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot1->xAxis, ui->CustomPlot1->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_client());
    bars1->setName("nombre du client selon sexe");
    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));

    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot1->replot();


    // move bars above graphs and grid below bars:
    ui->CustomPlot1->addLayer("abovemain", ui->CustomPlot1->layer("main"), QCustomPlot::limAbove);
    ui->CustomPlot1->addLayer("belowmain", ui->CustomPlot1->layer("main"), QCustomPlot::limBelow);
    ui->CustomPlot1->xAxis->grid()->setLayer("belowmain");
    ui->CustomPlot1->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"Femme"<<"Homme";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot1->xAxis->setTicker(textTicker);
    ui->CustomPlot1->xAxis->setSubTicks(false);
    ui->CustomPlot1->xAxis->setTickLength(0,4);
    ui->CustomPlot1->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot1->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot1->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot1->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot1->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot1->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot1->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot1->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot1->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot1->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot1->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot1->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot1->xAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot1->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot1->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot1->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot1->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot1->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot1->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot1->axisRect()->setBackground(axisRectGradient);

    ui->CustomPlot1->rescaleAxes();
    ui->CustomPlot1->xAxis->setRange(0, 7);
    ui->CustomPlot1->yAxis->setRange(0, 10);


}
void MainWindow::on_pushButton_50_clicked()
{
    MainWindow::makePlot_client();
}














void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
     MainWindow::makePlot_stock();


}

void MainWindow::on_pushButton_72_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_71_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_61_clicked()
{
    stock s;
    s.ajouter(ui);
    s.AfficherTable(ui);
}
void MainWindow::on_pushButton_62_clicked()
{
    if  (ui->tableView_8->selectionModel()->hasSelection())
        {
         stock s;


         s.supprimer(ui);
        s.AfficherTable(ui);
        }
}
void MainWindow::on_pushButton_63_clicked()
{
    stock s;
    s.Modifier(ui);
    s.AfficherTable(ui);
}
void MainWindow::on_pushButton_66_clicked()
{
    facture_stock f;
    f.ajouter(ui);
    f.AfficherTable(ui);
}
void MainWindow::on_pushButton_69_clicked()
{
    if  (ui->tableView_9->selectionModel()->hasSelection())
        {
         facture_stock f;


         f.supprimer(ui);
        f.AfficherTable(ui);
        }
}
void MainWindow::on_pushButton_64_clicked()
{
    facture_stock f;
    f.Modifier(ui);
    f.AfficherTable(ui);
}
QVector<double> MainWindow::Statistique_stock()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT PRIX_UNITAIRE FROM FACTURE_STOCK WHERE PRIX_UNITAIRE<=200");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT PRIX_UNITAIRE FROM FACTURE_STOCK WHERE 200<PRIX_UNITAIRE and PRIX_UNITAIRE<=400");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT PRIX_UNITAIRE FROM FACTURE_STOCK WHERE 400<PRIX_UNITAIRE and PRIX_UNITAIRE<=600");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT PRIX_UNITAIRE FROM FACTURE_STOCK WHERE 600<PRIX_UNITAIRE and PRIX_UNITAIRE<=800");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT PRIX_UNITAIRE FROM FACTURE_STOCK WHERE 800<PRIX_UNITAIRE and PRIX_UNITAIRE<=1000");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void MainWindow::makePlot_stock()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot2->xAxis, ui->CustomPlot2->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_stock());
    bars1->setAntialiased(false);
    bars1->setStackingGap(1);

    bars1->setName("Qte du Produit selon le prix unitaire");
    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot2->replot();
    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5;
    QVector<QString> labels;
    labels<<"0-200dt"<<"200dt-400dt"<<"400dt-600dt"<<"600dt-800dt"<<"800dt-1000dt";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot2->xAxis->setTicker(textTicker);
    ui->CustomPlot2->xAxis->setSubTicks(false);
    ui->CustomPlot2->xAxis->setTickLength(0,4);
    ui->CustomPlot2->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot2->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot2->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot2->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot2->yAxis->setLabelColor(Qt::white);
    ui->CustomPlot2->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot2->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot2->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot2->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 1, Qt::DotLine));
    ui->CustomPlot2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 1, Qt::DotLine));
    ui->CustomPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
   // ui->CustomPlot2->xAxis->grid()->setSubGridVisible(true);
   // ui->CustomPlot2->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot2->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot2->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot2->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot2->axisRect()->setBackground(axisRectGradient);
    ui->CustomPlot2->rescaleAxes();
    ui->CustomPlot2->xAxis->setRange(0, 7);
    ui->CustomPlot2->yAxis->setRange(0, 10);


}
void MainWindow::on_pushButton_70_clicked()
{    MainWindow::makePlot_stock();
}
void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget->setCurrentIndex(19);
}void MainWindow::on_pushButton_24_clicked()
{
     ui->stackedWidget->setCurrentIndex(20);
}void MainWindow::on_pushButton_25_clicked()
{
     ui->stackedWidget->setCurrentIndex(21);
}
void MainWindow::on_pushButton_75_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}
void MainWindow::on_pushButton_73_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}
void MainWindow::on_pushButton_74_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

/*void MainWindow::on_pushButton_30_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}
*/

void MainWindow::on_pushButton_26_clicked()
{
    offre o;
    o.ajouter(ui);
    o.AfficherTable(ui);
}

void MainWindow::on_pushButton_76_clicked()
{
    offre o;
    o.Modifier(ui);
    o.AfficherTable(ui);

}

void MainWindow::on_pushButton_77_clicked()
{
    if  (ui->tableView_10->selectionModel()->hasSelection())
        {
         offre o;


         o.supprimer(ui);
        o.AfficherTable(ui);
        }

}

void MainWindow::on_pushButton_286_clicked()
{
    evenement o;
    o.ajouter(ui);
    o.AfficherTable(ui);
}

void MainWindow::on_pushButton_288_clicked()
{
    evenement o;
    o.Modifier(ui);
    o.AfficherTable(ui);
}

void MainWindow::on_pushButton_287_clicked()
{
    if  (ui->tableView_31->selectionModel()->hasSelection())
        {
         evenement o;


         o.supprimer(ui);
        o.AfficherTable(ui);
        }
}


QVector<double> MainWindow::Statistique_marketing()
{QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT BUDGET FROM EVENEMENT WHERE BUDGET<=200");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT BUDGET FROM EVENEMENT WHERE 200<BUDGET and BUDGET<=400");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT BUDGET FROM EVENEMENT WHERE 400<BUDGET and BUDGET<=600");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT BUDGET FROM EVENEMENT WHERE 600<BUDGET and BUDGET<=800");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT BUDGET FROM EVENEMENT WHERE 800<BUDGET and BUDGET<=1000");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void MainWindow::makePlot_marketing()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot3->xAxis, ui->CustomPlot3->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_marketing());
    bars1->setAntialiased(false);
    bars1->setStackingGap(1);

    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot3->replot();
    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5;
    QVector<QString> labels;
    labels<<"0-200dt"<<"200dt-400dt"<<"400dt-600dt"<<"600dt-800dt"<<"800dt-1000dt";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot3->xAxis->setTicker(textTicker);
    ui->CustomPlot3->xAxis->setSubTicks(false);
    ui->CustomPlot3->xAxis->setTickLength(0,4);
    ui->CustomPlot3->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot3->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot3->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot3->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot3->yAxis->setLabelColor(Qt::white);
    ui->CustomPlot3->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot3->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot3->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot3->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot3->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 1, Qt::DotLine));
    ui->CustomPlot3->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 1, Qt::DotLine));
    ui->CustomPlot3->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot3->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
   // ui->CustomPlot3->xAxis->grid()->setSubGridVisible(true);
   // ui->CustomPlot3->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot3->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot3->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot3->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot3->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot3->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot3->axisRect()->setBackground(axisRectGradient);
    ui->CustomPlot3->rescaleAxes();
    ui->CustomPlot3->xAxis->setRange(0, 7);
    ui->CustomPlot3->yAxis->setRange(0, 10);


}
void MainWindow::on_pushButton_289_clicked()
{
    MainWindow::makePlot_marketing();
}

void MainWindow::on_tableView_10_activated(const QModelIndex &index)
{

}
void MainWindow::on_pushButton_65_clicked()
{
 stock *e= new stock();
 ui->tableView_8->setModel(e->trierStock());

}
void MainWindow::on_pushButton_60_clicked()
{
    QString valeur=ui->lineEdit_12->text();
    stock *e=new stock();
    ui->tableView_8->setModel(e->rechercherStock(valeur));

}
int MainWindow::on_pushButton_67_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/facture_stock.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/facture_stock");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString id_fournisseur=ui->lineEdit_39->text();
           QString reference_produit =ui->lineEdit_40->text();
           QString description=ui->lineEdit_41->text();




           QString quantite =ui->lineEdit_42->text();
           QString prix_unitaire =ui->lineEdit_43->text();


           painter.drawImage(40,40,imagen);
           painter.drawText(160, 280, id_fournisseur);

           painter.drawText(169, 300, reference_produit);
           painter.drawText(160, 360, description);
           painter.drawText(160, 380, quantite);
           painter.drawText(160, 400, prix_unitaire);


         // painter.drawText(160, 363, df);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }


}
int MainWindow::on_pushButton_78_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/onwritable.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/offre");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString nom=ui->lineEdit_11->text();
           QString identifiant =ui->lineEdit_45->text();
           QString date=ui->lineEdit_47->text();




           QString client_cible =ui->lineEdit_46->text();

           painter.drawImage(40,40,imagen);
           painter.drawText(160, 280, nom);

           painter.drawText(169, 300, identifiant);
           painter.drawText(160, 360, date);
           painter.drawText(160, 380, client_cible);

         // painter.drawText(160, 363, df);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}
int MainWindow::on_pushButton_79_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/event.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/evenement");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString id=ui->lineEdit_144->text();
           QString nom_evenement=ui->lineEdit_143->text();
           QString date=ui->lineEdit_142->text();




           QString  lieu=ui->lineEdit_145->text();
           QString budget =ui->lineEdit_146->text();


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, id);

           painter.drawText(180, 300, nom_evenement);
           painter.drawText(180, 360, date);
           painter.drawText(180, 380, lieu);

           painter.drawText(160, 400, budget);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}
int MainWindow::on_pushButton_58_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/livraison.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/livraison");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString localisation=ui->lineEdit_31->text();
           QString n_facture=ui->lineEdit_32->text();
           QString n_commande=ui->lineEdit_33->text();




           QString  nom_prenom=ui->lineEdit_34->text();
           QString date =ui->lineEdit_35->text();


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, localisation);

           painter.drawText(180, 300, n_facture);
           painter.drawText(180, 360, n_commande);
           painter.drawText(180, 380, nom_prenom);

           painter.drawText(160, 400, date);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}

int MainWindow::on_pushButton_80_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/stock.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/stock");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString code_produit=ui->lineEdit_12->text();
           QString reference=ui->lineEdit_13->text();
           QString fournisseur=ui->lineEdit_14->text();




           QString  prix=ui->lineEdit_15->text();
           QString remise =ui->lineEdit_16->text();


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, code_produit);

           painter.drawText(180, 300, reference);
           painter.drawText(180, 360, fournisseur);
           painter.drawText(180, 380, prix);

           painter.drawText(160, 400, remise);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}
int MainWindow::on_pushButton_57_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/facture.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/facture");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString N_facture=ui->lineEdit_27->text();
           QString N_commande=ui->lineEdit_28->text();
           QString montant=ui->lineEdit_30->text();




           QString  affaire=ui->lineEdit_29->text();
           QString reglement =ui->lineEdit_36->text();


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, N_facture);

           painter.drawText(180, 300, N_commande);
           painter.drawText(180, 360, montant);
           painter.drawText(180, 380, affaire);

           painter.drawText(160, 400, reglement);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}
int MainWindow::on_pushButton_56_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/commande.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/commande");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString N_commande=ui->lineEdit_22->text();
           QString Nom_prenom=ui->lineEdit_23->text();
           QString Nom_produit=ui->lineEdit_24->text();




           QString  Quantite=ui->lineEdit_25->text();
           QString Prix =ui->lineEdit_26->text();


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, N_commande);

           painter.drawText(180, 300, Nom_prenom);
           painter.drawText(180, 360, Nom_produit);
           painter.drawText(180, 380, Quantite);

           painter.drawText(160, 400, Prix);
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}


void MainWindow::on_pushButton_82_clicked()
{
 offre *e= new offre();
 ui->tableView_10->setModel(e->trierOffre());

}
void MainWindow::on_pushButton_83_clicked()
{
    QString valeur=ui->lineEdit_11->text();
    offre *e=new offre();
    ui->tableView_10->setModel(e->rechercherOffre(valeur));

}


void MainWindow::on_pushButton_84_clicked()
{
 evenement *e= new evenement();
 ui->tableView_31->setModel(e->trierEvent());

}
void MainWindow::on_pushButton_85_clicked()
{
    QString valeur=ui->lineEdit_143->text();
    evenement *e=new evenement();
    ui->tableView_31->setModel(e->rechercherEvent(valeur));

}

void MainWindow::on_pushButton_86_clicked()
{
 commande *e= new commande();
 ui->tableView_3->setModel(e->trierCommande());

}
void MainWindow::on_pushButton_87_clicked()
{
    QString valeur=ui->lineEdit_22->text();
    commande *e=new commande();
    ui->tableView_3->setModel(e->rechercherCommande(valeur));

}
void MainWindow::on_pushButton_88_clicked()
{
 facture *e= new facture();
 ui->tableView_4->setModel(e->trierFacture());

}
void MainWindow::on_pushButton_89_clicked()
{ std::cout<<"oooooooo"<< std::endl;
QString valeur=ui->lineEdit_27->text();
    facture *e=new facture();
    ui->tableView_4->setModel(e->rechercherFacture(valeur));

}


void MainWindow::on_pushButton_90_clicked()
{
 Client *e= new Client();
 ui->tableView_5->setModel(e->trierClient());


}
void MainWindow::on_pushButton_91_clicked()
{
    QString valeur=ui->lineEdit_4->text();
    Client *e=new Client();
    ui->tableView_5->setModel(e->rechercherClient(valeur));

}


int MainWindow::on_pushButton_53_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/demande.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/demande");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString N_demande=ui->lineEdit_17->text();
           QString Sujet=ui->lineEdit_18->text();
           QString Description=ui->lineEdit_10->text();





          /* QString  affaire=ui->lineEdit_29->text();
           QString reglement =ui->lineEdit_36->text();*/


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, N_demande);

           painter.drawText(180, 300, Sujet);
           painter.drawText(180, 360, Description);
        /*   painter.drawText(180, 380, affaire);

           painter.drawText(160, 400, reglement);*/
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}
int MainWindow::on_pushButton_54_clicked()
{
    QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("C:/Users/DALI/Desktop/PDF/reclamation.pdf");
           QPainter painter;
           QImage imagen("C:/Users/DALI/Desktop/PDF/reclamation");
           if (! painter.begin(&printer)) { // failed to open file
               qWarning("failed to open file, is it writable?");
               return 1;
           }


           QString N_reclamation=ui->lineEdit_19->text();
           QString sujet=ui->lineEdit_20->text();
           QString description=ui->lineEdit_37->text();




         /*  QString  affaire=ui->lineEdit_29->text();
           QString reglement =ui->lineEdit_36->text();*/


           painter.drawImage(40,40,imagen);
           painter.drawText(180, 280, N_reclamation);

           painter.drawText(180, 300, sujet);
           painter.drawText(180, 360, description);
         /*  painter.drawText(180, 380, affaire);

           painter.drawText(160, 400, reglement);*/
           //painter.drawText(160, 625, c);

           painter.end();
           QString file_name = QFileDialog::getOpenFileName(this,"open a file","c://");
           QFile file (file_name);

           if (!file.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,"WARNING","File not open");
           }
           QTextStream in(&file);
           QString text = in.readAll();
           file.close();
           QPrinter printer1 (QPrinter::ScreenResolution);
               printer1.setDocName("ArithmoTarot - Scores");
               printer1.setPaperSize(QPrinter::A4);
               printer1.setOrientation(QPrinter::Portrait);

               QPrintDialog printDialog(&printer1, this);
               printDialog.setOption(QAbstractPrintDialog::PrintToFile);

               if (printDialog.exec() == QDialog::Accepted)
               {
                   QPainter painter1;
                   painter1.begin(&printer);
                   painter1.setPen(Qt::black);
                   painter1.setFont(QFont("Arial", 12));
                   painter1.drawText(rect(), Qt::AlignLeft | Qt::TextSingleLine, "<em>ArithmoTarot - Scores</em>");
                   painter1.drawText(QPointF(100,100), text);
                   painter1.end();
               }

}
void MainWindow::  on_pushButton_10_clicked()
{
    QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();

        if((username == "chaima" && password == "chaima")||(username == "CRM" && password == "CRM"))
        {
            QMessageBox::information(this, "Login" , "Username and Password is correct");

            ui->stackedWidget->setCurrentIndex(1);



        }
        else
        {
            QMessageBox::warning(this, "Login", "Username and Password is not correct");
        }



}

void MainWindow::on_pushButton_52_clicked()
{
    smtp *s = new smtp();
    s->setDestMail("hamza.rahoui@esprit.tn");
    s->setDestNom(".");
    s->setMailTitre(("offre"));
    s->setContenue("hi");
    s->sendMail();




}
void MainWindow:: on_pushButton_98_clicked ()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow ::on_pushButton_19_clicked ()
{
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow ::on_pushButton_20_clicked ()
{
    ui->stackedWidget->setCurrentIndex(23);
}


void MainWindow::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_99_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_pushButton_59_clicked()
{
    rdv *a=new rdv();
    ui->tableView_11->setModel(a->affichage(ui->calendarWidget->selectedDate().toString("dd/MM/yyyy")));

}

void MainWindow::on_pushButton_110_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);


}

void MainWindow::on_pushButton_111_clicked()
{
    rdv *a=new rdv();
       QString j=ui->tableView_11->selectionModel()->selectedIndexes().at(0).data().toString();
       if(a->supprimer(j))
       {
           QMessageBox::information(this,"confirmation","Suppression avec Succ??e.");
       }
       else                {  QMessageBox::critical(this,"nope","Echec de Suppression.");}

}

void MainWindow::on_pushButton_121_clicked()
{
    rdv *a=new rdv();
    ui->tableView_11->setModel(a->affichagetout());
}

void MainWindow::on_pushButton_117_clicked()
{
    QPrinter printer;

    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));
    if (dialog.exec() != QDialog::Accepted) {
      return;
    }


    QPainter painter;

    bool success = painter.begin(&printer);
    Q_ASSERT(success);

    double xscale = printer.pageRect().width()/double(ui->tableView_11->width());
    double yscale = printer.pageRect().height()/double(ui->tableView_11->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                      printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/3, -height()/3);

    ui->tableView_11->render(&painter);
    painter.end();

}

void MainWindow::on_pushButton_244_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void MainWindow::on_pushButton_245_clicked()
{
    liv *a=new liv();
    ui->tableView_23->setModel(a->affichage(ui->calendarWidget->selectedDate().toString("dd/MM/yyyy")));
}

void MainWindow::on_pushButton_246_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void MainWindow::on_pushButton_247_clicked()
{
    liv *a=new liv();
       QString j=ui->tableView_23->selectionModel()->selectedIndexes().at(0).data().toString();
       if(a->supprimer(j))
       {
           QMessageBox::information(this,"confirmation","Suppression avec Succ??e.");
       }
       else                {  QMessageBox::critical(this,"nope","Echec de Suppression.");}
}

void MainWindow::on_pushButton_248_clicked()
{
    liv *a=new liv();
    ui->tableView_23->setModel(a->affichagetout());
}

void MainWindow::on_pushButton_249_clicked()
{
    QPrinter printer;

    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));
    if (dialog.exec() != QDialog::Accepted) {
      return;
    }


    QPainter painter;

    bool success = painter.begin(&printer);
    Q_ASSERT(success);

    double xscale = printer.pageRect().width()/double(ui->tableView_23->width());
    double yscale = printer.pageRect().height()/double(ui->tableView_23->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                      printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/3, -height()/3);

    ui->tableView_23->render(&painter);
    painter.end();


}

void MainWindow::on_pushButton_21_clicked()
{
    rdv *b=new rdv();
        ui->tableView_11->setModel(b->recherche(ui->lineEdit_48->text()));

}

void MainWindow::on_pushButton_243_clicked()
{
    liv *b=new liv();
        ui->tableView_2->setModel(b->recherche(ui->lineEdit_97->text()));
}

void MainWindow::on_pushButton_250_clicked()
{
    rdv *a=new rdv(ui->lineEdit_98->text(),ui->lineEdit_101->text(),ui->lineEdit_100->text(),ui->comboBox_5->currentText(),ui->lineEdit_99->text(),ui->dateEdit->text());
    if (a->ajouter())
        QMessageBox::information(this,"succes","ajout reussis");
    else QMessageBox::critical(this,"fail","non reussis");
}

void MainWindow::on_pushButton_251_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}
void MainWindow::on_pushButton_262_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}
void MainWindow::on_pushButton_263_clicked()
{
    rdv *a=new rdv();
    if(a->modifier(ui->lineEdit_110->text(),ui->lineEdit_107->text(),ui->lineEdit_109->text(),ui->comboBox_7->currentText(),ui->lineEdit_108->text(),ui->dateEdit_3->text()))
        QMessageBox::information(this,"succes","modification reussis");
    else QMessageBox::critical(this,"fail","non reussis");
}
void MainWindow::on_pushButton_406_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}
void MainWindow::on_pushButton_407_clicked()
{
        {
        ui->stackedWidget->setCurrentIndex(22);

    }
}
void MainWindow::on_pushButton_408_clicked()
{
    liv *a=new liv(ui->lineEdit_182->text(),ui->lineEdit_179->text(),ui->lineEdit_181->text(),ui->dateEdit_5->text(),ui->lineEdit_180->text());
    if (a->ajouter())
        QMessageBox::information(this,"succes","ajout reussis");
    else QMessageBox::critical(this,"fail","non reussis");
}
void MainWindow::on_pushButton_545_clicked()
{
    liv *a=new liv();
    if(a->modifier(ui->lineEdit_241->text(),ui->lineEdit_243->text(),ui->lineEdit_242->text(),ui->dateEdit_7->text(),ui->lineEdit_244->text()))
        QMessageBox::information(this,"succes","modification reussis");
    else QMessageBox::critical(this,"fail","non reussis");
}
void MainWindow::on_pushButton_548_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}
void MainWindow::on_pushButton_543_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}


void MainWindow::on_pushButton_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);

}
QVector<double> MainWindow::Statistique_agenda()
{
    QSqlQuery q;
    QVector<double> stat(2);
    stat[0]=0;
    stat[1]=0;

    q.prepare("SELECT SEXE_CLIENT FROM RDV WHERE SEXE_CLIENT='Homme'");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT SEXE_CLIENT FROM RDV WHERE SEXE_CLIENT='Femme'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }

    return stat;
}
void MainWindow::makePlot_agenda()
{
    // prepare data:
    QVector<double> x3(2), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot4->xAxis, ui->CustomPlot4->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_agenda());
    bars1->setName("nombre du client selon sexe");
    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));

    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot4->replot();


    // move bars above graphs and grid below bars:
    ui->CustomPlot4->addLayer("abovemain", ui->CustomPlot4->layer("main"), QCustomPlot::limAbove);
    ui->CustomPlot4->addLayer("belowmain", ui->CustomPlot4->layer("main"), QCustomPlot::limBelow);
    ui->CustomPlot4->xAxis->grid()->setLayer("belowmain");
    ui->CustomPlot4->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"Homme"<<"Femme";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot4->xAxis->setTicker(textTicker);
    ui->CustomPlot4->xAxis->setSubTicks(false);
    ui->CustomPlot4->xAxis->setTickLength(0,4);
    ui->CustomPlot4->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot4->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot4->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot4->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot4->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot4->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot4->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot4->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot4->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot4->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot4->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot4->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot4->xAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot4->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot4->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot4->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot4->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot4->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot4->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot4->axisRect()->setBackground(axisRectGradient);

    ui->CustomPlot4->rescaleAxes();
    ui->CustomPlot4->xAxis->setRange(0, 7);
    ui->CustomPlot4->yAxis->setRange(0, 10);


}
void MainWindow::on_pushButton_81_clicked()
{
    MainWindow::makePlot_agenda();
}
void MainWindow::on_pushButton_92_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

