#include "game.h"

Game::Game()
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
    Game::initGame();

}

Game::~Game()
{
    delete _orchestrator;
}

/**
 * Init the orchestrator and launch the game
 */
void Game::initGame()
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
 * @brief Game::newRound
 * Init new round
 */
void Game::newRound()
{
    cout << "Game: New Round!" << endl;
    _orchestrator->doRound();
}
