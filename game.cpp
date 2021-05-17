#include "game.h"

Game::Game()
{
    Orchestrator *orchestrator = new Orchestrator(_config);
    _orchestrator = *orchestrator;
    Game::initGame();
}

Game::~Game()
{

}

/**
 * Request the user to give default config and then create an environment
 */
void Game::initGame()
{    
    _config = {
            100,
            50,
            5,
            10,
            15,
            10,
            10,
            15,
            1,
            2,
            3,
            4,
            15,
    };
    cout << "Init Game" << _config.ageLarva <<  endl;
}

/**
 * @brief Game::newRound
 * Init new round
 */
void Game::newRound()
{
    cout << "Game: New Round!" << endl;
}
