/*
 * File:   main.cpp
 * Author: morwin
 *
 * Created on 30 липня 2011, 11:17
 */

#include <QtGui/QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    
    MainWindow mainWin;
    mainWin.setSizeIncrement(400, 300);
    mainWin.show();
    
    // create and show your widgets here

    return app.exec();
}
