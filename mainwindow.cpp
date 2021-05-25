#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QGridLayout *gridLayout = new QGridLayout;
    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    QPushButton *b4 = new QPushButton("D");
    QPushButton *b5 = new QPushButton("E");
    QPushButton *b6 = new QPushButton("F");

    // addWidget(*Widget, row, column, rowspan, colspan)
    // 0th row
    gridLayout->addWidget(b1,0,0,1,1);
    gridLayout->addWidget(b2,0,1,1,1);
    gridLayout->addWidget(b3,0,2,1,1);

    // 1st row
    gridLayout->addWidget(b4,1,0,1,1);

    // 2nd row with 2-column span
    gridLayout->addWidget(b5,2,0,1,2);

    // 3rd row with 3-column span
    gridLayout->addWidget(b6,3,0,1,3);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);

    // Window title
    w->setWindowTitle("Grid Layouts (3x4)");

    // Display
    w->show();

    this->setCentralWidget(w);

    // Uncomment to use QML
//    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

