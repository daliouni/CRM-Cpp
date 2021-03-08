#ifndef GEOLOCALISATION_H
#define GEOLOCALISATION_H

#include <QString>
#include <QDesktopServices>
#include "MainWindow.h"
#include "ui_MainWindow.h"
using namespace  std ;

class GPS
{
public:
    GPS();
     void search(const QString &Address);

};
#endif // GEOLOCALISATION_H
