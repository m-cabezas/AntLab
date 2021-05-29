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
    MainWindow::initGame();
    _gridLayout = new QGridLayout;

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
    int i = 0;
    while (i < 100)
    {
        newRound();
        i++;
    }

    cout << "End Game" << endl;
}

/**
 * @brief MainWindow::newRound
 * Init new round
 */
void MainWindow::newRound()
{
    cout << "Game: New Round!" << endl;
    _orchestrator->doRound();
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
    delete _orchestrator;
    delete ui;
}

