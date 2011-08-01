#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow() {

    centralWidget = new QWidget;
    textTime = new QLabel(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(resUpdate()));
    timer->start(1000);

    QFont font;
    font.setPointSize(24);
    font.setBold(true);

    centralWidget->setFont(font);
    

    this->time = 60;

    createTimer();

    QVBoxLayout *centralLayout = new QVBoxLayout;    
    centralLayout->addWidget(textTime);

    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);    

    createActions();
    createMenus();
}

void MainWindow::helloWorld() {
    QMessageBox::information(this, "Hello", "Hello me!!!");
}

void MainWindow::resUpdate() {
    this->time--;
    textTime->setText(QString().sprintf("%d", this->time));
}

void MainWindow::createActions() {
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open..."), this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));


    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(exitAction);

    menuBar()->addSeparator();

}

void MainWindow::newFile() {
    QMessageBox::information(this, "New file", "Create new file");
}

void MainWindow::open() {
    QMessageBox::information(this, "Open file", "Open file");
}

void MainWindow::createTimer() {
    textTime->setText(QString().sprintf("%d", this->time));
}