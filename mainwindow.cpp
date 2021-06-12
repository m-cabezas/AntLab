#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _config = {
            500,    // maxFood
            20,     // maxPopAnthill
            200,    // maxFoodFoodSpawner
            5,      // ageLarva
            10,     //ageWorker
            15,     //ageWarrior
            20,     //ageQueen
            60,     //lifeLarva
            70,     //lifeWorker
            150,     //lifeWarrior
            100,     //lifeQueen
            1,      //consLarva
            2,      //consWorker
            3,      //consWarrior
            4,      //consQueen
            40,     //capacityWarrior
            4,      //nbEggInit
            3,      //nbLarvaInit
            3,      //nbWorkerInit
            8,      //nbWarriorInit
            30,     //nbFoodSpawnerInit
            50      //nbObstacleInit
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
    while (true)
    {
        cout << "ROUND : " << i << endl;
    	initializeGrid();
        int res = _orchestrator->doRound();
        if(res == 1) {
            cout << "London Bridge is Down! Our beloved Queen passed away this morning..." << endl;
            break;
        }
        Sleep(200);
		system("CLS");
        i++;
        cout << "_________________________________________________________________________________________________________________________________________" << endl;
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

