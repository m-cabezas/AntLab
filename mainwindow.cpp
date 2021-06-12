#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _config = {
            100,    // maxFood
            50,     // maxPopAnthill
            100,    // maxFoodFoodSpawner
            5,      // ageLarva
            10,     //ageWorker
            15,     //ageWarrior
            10,     //lifeLarva
            10,     //lifeWorker
            13,     //lifeWarrior
            15,     //lifeQueen
            1,      //consLarva
            2,      //consWorker
            3,      //consWarrior
            4,      //consQueen
            15,     //capacityWarrior
            4,      //nbEggInit
            3,      //nbLarvaInit
            3,      //nbWorkerInit
            8,      //nbWarriorInit
            20,     //nbFoodSpawnerInit
            20      //nbObstacleInit
    };
    _orchestrator = new Orchestrator(_config);
    _gridLayout = new QGridLayout;
    MainWindow::initGame();

    // Uncomment to use QML
//    ui->setupUi(this);

}

/**
 * Init the orchestrator and launch the MainWindow
 */
void MainWindow::initGame()
{
    cout << "Init Game" << endl;
    _orchestrator->initOrch(_config);
    initializeGrid(_orchestrator->getDimension());
    int i = 0;
    while (i < 20)
    {
        newRound(i);
        Sleep(100);
        i++;
    }
    cout << "End Game" << endl;
}

/**
 * @brief MainWindow::newRound
 * Init new round
 */
void MainWindow::newRound(int roundNumber)
{
    cout << "Game: New Round! Round " << roundNumber << endl;
    _orchestrator->doRound();
}

void MainWindow::initializeGrid(pair<int, int> dimensions) {
    for (int x = 0;x < dimensions.first;x++) {
        for (int y = 0;y < dimensions.second;y++) {
            QLabel * lb = new QLabel();
            lb->setStyleSheet("border: 1px solid black;");
            _gridLayout->addWidget(lb,y,x,1,1);
        }
    }
    // Create a widget
    QWidget *w = new QWidget();
    _gridLayout->setSpacing(0);
    // Set the grid layout as a main layout
    w->setLayout(_gridLayout);
    // Window title
    w->setWindowTitle("Grid Layouts");
    // Display
    w->show();
    this->setCentralWidget(w);
}

MainWindow::~MainWindow()
{
    delete _orchestrator;
    delete ui;
}

