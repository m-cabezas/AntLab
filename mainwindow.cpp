#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>

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
    int i = 0;
    while (i < 100)
    {
    	initializeGrid();
        newRound(i);
        Sleep(100);
		system("CLS");
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

/**
 * @brief MainWindow::initializeGrid display an process the console UI
 */
void MainWindow::initializeGrid() {
    pair<int,int> dimensions = _orchestrator->getDimension();
    string * display = new string();
    for (int i = 0;i < dimensions.first+2; i++) {
        display->append("*");
    }
    display->append("\n");
    for (int y = 0;y < dimensions.second;y++) {
        display->append("*");
        for (int x = 0;x < dimensions.first;x++) {
            switch (_orchestrator->getMapEntity(x,y)) {
                case 1:
                    display->append(" ");
                    break;
                case 3:
                    display->append("F");
                    break;
                case 2:
                    display->append("O");
                    break;
                case 4:
                    display->append("A");
                    break;
                case 5:
                    display->append("W");
                    break;
            }
        }
        display->append("*");
        display->append("\n");
    }
    for (int n = 0;n < dimensions.first+2; n++) {
        display->append("*");
    }
    cout << *display << endl;
}

MainWindow::~MainWindow()
{
    delete _orchestrator;
    delete ui;
}

