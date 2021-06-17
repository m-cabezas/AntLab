#include "game.h"

#include <windows.h>

/***
 * @brief default constructor of game
 */
Game::Game() {
    _config = {
            500,    // maxFood
            20,     // maxPopAnthill
            400,    // maxFoodFoodSpawner
            5,      // ageLarva
            8,     //ageWorker
            16,     //ageWarrior
            30,     //ageQueen
            60,     //lifeLarva
            70,     //lifeWorker
            250,     //lifeWarrior
            300,     //lifeQueen
            1,      //consLarva
            2,      //consWorker
            3,      //consWarrior
            5,      //consQueen
            60,     //capacityWarrior
            4,      //nbEggInit
            3,      //nbLarvaInit
            3,      //nbWorkerInit
            8,      //nbWarriorInit
            30,     //nbFoodSpawnerInit
            50      //nbObstacleInit
    };
    _orchestrator = new Orchestrator(_config);
    Game::initGame();
}

/**
 * Init the orchestrator and launch the MainWindow
 */
void Game::initGame() {
    cout << "Init Game" << endl;
    _orchestrator->initOrch(_config);
    refreshGrid();
    int i = 0;
    while (true) {
        if (!newRound(i)) {
            break;
        }
        i++;
    }
    cout << "End Game" << endl;
}

/***
 * @brief Init a new round
 * @param roundNumber
 */
bool Game::newRound(int roundNumber) {
    cout << "ROUND : " << roundNumber << endl;    
    int res = _orchestrator->doRound();
    refreshGrid();
    if (res == 1) {
        cout << "London Bridge is Down! Our beloved Queen passed away this morning..." << endl;
        return false;
    }
    Sleep(200);
    system("CLS");
    cout
            << "_________________________________________________________________________________________________________________________________________"
            << endl;
    return true;
}

/**
 * @brief display an process the console UI
 */
void Game::refreshGrid() {
    pair<int, int> dimensions = _orchestrator->getDimension();
    string *display = new string();
    for (int i = 0; i < dimensions.first + 2; i++) {
        display->append("*");
    }
    display->append("\n");
    for (int y = 0; y < dimensions.second; y++) {
        display->append("*");
        for (int x = 0; x < dimensions.first; x++) {
            switch (_orchestrator->getMapEntity(x, y)) {
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
    for (int n = 0; n < dimensions.first + 2; n++) {
        display->append("*");
    }
    cout << *display << endl;
}

/***
 * @brief Game default destructor
 */
Game::~Game() {
    delete _orchestrator;
}

