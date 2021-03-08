#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();



    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_112_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton_102_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pushButton_103_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_105_clicked();

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_pushButton_120_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_51_clicked ();
    void on_pushButton_49_clicked ();
    void on_pushButton_40_clicked ();
    void on_pushButton_42_clicked ();
    void on_pushButton_41_clicked ();
    void on_tableView_5_clicked(const QModelIndex &index);
    void on_pushButton_43_clicked ();
    void on_pushButton_44_clicked ();
    void on_pushButton_45_clicked ();

    void on_tableView_6_clicked(const QModelIndex &index);
    void on_pushButton_46_clicked ();
    void on_pushButton_47_clicked ();
    void on_pushButton_48_clicked ();
    void on_pushButton_50_clicked ();


    void on_tableView_7_clicked(const QModelIndex &index);









    void on_tableView_2_clicked(const QModelIndex &index);

    void makePlot_vente ();
    QVector<double> Statistique_vente();
    void makePlot_client ();
    QVector<double> Statistique_client();
    void makePlot_stock ();
    QVector<double> Statistique_stock();
    void makePlot_marketing ();
    QVector<double> Statistique_marketing();
    void makePlot_agenda();
    QVector<double> Statistique_agenda();







   // void on_pushButton_52_clicked();

  //  void on_pushButton_53_clicked();

   void on_pushButton_55_clicked();
   void on_pushButton_81_clicked();
   void on_pushButton_92_clicked();



   // void on_pushButton_56_clicked();

 //   void on_pushButton_57_clicked();

    //void on_pushButton_58_clicked();


    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_63_clicked();
    void on_pushButton_66_clicked();
    void on_pushButton_69_clicked();
    void on_pushButton_64_clicked();
    void on_pushButton_70_clicked();
    void on_pushButton_73_clicked();
    void on_pushButton_74_clicked();
    void on_pushButton_75_clicked();









    void on_pushButton_26_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_286_clicked();

    void on_pushButton_288_clicked();

    void on_pushButton_287_clicked();

    void on_tableView_31_activated(const QModelIndex &index);

    void on_pushButton_289_clicked();

    void on_tableView_10_activated(const QModelIndex &index);
    void on_pushButton_65_clicked();
    void on_pushButton_60_clicked();
    int on_pushButton_67_clicked();
    int on_pushButton_78_clicked();
    int on_pushButton_79_clicked();
    int on_pushButton_80_clicked();
    int on_pushButton_58_clicked();
    int on_pushButton_57_clicked();
    int on_pushButton_56_clicked();
    int on_pushButton_54_clicked();
    int on_pushButton_53_clicked();
    void on_pushButton_52_clicked();
    void  on_pushButton_82_clicked();
    void  on_pushButton_83_clicked();
    void on_pushButton_84_clicked();
    void on_pushButton_85_clicked();
    void on_pushButton_86_clicked();
    void on_pushButton_87_clicked();
    void on_pushButton_88_clicked();
    void on_pushButton_89_clicked();
    void on_pushButton_90_clicked();
    void on_pushButton_91_clicked();
    void on_pushButton_98_clicked ();
    void on_pushButton_19_clicked ();
    void on_pushButton_20_clicked ();


    void on_pushButton_10_clicked();



    void on_pushButton_109_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_121_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_244_clicked();

    void on_pushButton_245_clicked();

    void on_pushButton_246_clicked();

    void on_pushButton_247_clicked();

    void on_pushButton_248_clicked();

    void on_pushButton_249_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_243_clicked();

    void on_pushButton_250_clicked();

    void on_pushButton_251_clicked();
    void on_pushButton_262_clicked();
    void on_pushButton_263_clicked();
    void on_pushButton_406_clicked();
    void on_pushButton_407_clicked();
    void on_pushButton_408_clicked();
    void on_pushButton_545_clicked();
    void on_pushButton_543_clicked();
    void on_pushButton_548_clicked();









private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
