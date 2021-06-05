#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <utility>
#include <string>
#include <iostream>
#include "orchestrator.h"
#include "util.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initializeGrid(pair<int,int> dimensions);
    void initGame();
    CONFIG getConfig();

private:

    //Attributs
    CONFIG _config;
    Orchestrator * _orchestrator;
    QGridLayout * _gridLayout;
    Ui::MainWindow *ui;

    //Methods
    void newRound();
};
#endif // MAINWINDOW_H
