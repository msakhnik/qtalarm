/* 
 * File:   mainwindow.h
 * Author: morwin
 *
 * Created on 30 липня 2011, 11:20
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
using namespace std;

class QAction;
class QLabel;
class Spreadsheet;
class QWidget;
class QFont;
class QTimer;

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    void helloWorld();
    int time;

private slots:
    void newFile();
    void open();
    void resUpdate();
private:
    void createActions();
    void createTimer();
    void createMenus();
    bool okToContinue();    

    QWidget *centralWidget;
    QFont *font;

    QAction *newAction;
    QAction *openAction;
    QAction *exitAction;

    QMenu *fileMenu;
    QLabel *textTime;
    QTimer *timer;
};



#endif	/* MAINWINDOW_H */