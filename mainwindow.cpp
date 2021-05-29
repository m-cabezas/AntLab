#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _gridLayout = new QGridLayout;

    // Uncomment to use QML
//    ui->setupUi(this);

}

void MainWindow::InitializeGrid(std::pair<int, int> dimensions) {
    for (int x = 0;x < dimensions.first;x++) {
        for (int y = 0;y < dimensions.second;y++) {
            QLabel * lb = new QLabel();
            _gridLayout->addWidget(lb,y,x,1,1);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

