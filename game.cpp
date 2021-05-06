#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}

/**
 * Request the user to give default config and then create an environment
 */
void Game::initGame()
{
    defaultConfig = 2;
    std::cout << "hello";
}

/**
 * @brief Game::newRound
 * Init new round
 */
void Game::newRound()
{
    std::cout << "Game: New Round!";
}
