#include "game.h"

Game::Game()
{
    Game::initGame();
    Orchestrator *orchestrator = new Orchestrator(_config);
    _orchestrator = *orchestrator;
}

Game::~Game()
{

}

/**
 * Request the user to give default config and then create an orchestrator
 */
void Game::initGame()
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
            5,      //nbWarriorInit
            10,     //nbFoodSpawnerInit
            20      //nbObstacleInit
    };

    cout << "Init Game" << _config.ageLarva <<  endl;
    _orchestrator.initOrch(_config);
}

/**
 * @brief Game::newRound
 * Init new round
 */
void Game::newRound()
{
    cout << "Game: New Round!" << endl;
}
