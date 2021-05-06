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
    cout << "Init Game" << endl;

    //@TODO : remplacer CONFIG par des paramètres dans chaque constructeur ou
    // passer Game à tout le monde avec Getters et Setters pour accéder à feu "CONFIG"

    //    CONFIG.insert(std::make_pair("maxFood", 100));
    //    CONFIG.insert(std::make_pair("maxPopAnthill", 50));
    //    CONFIG.insert(std::make_pair("ageLarva", 5));
//          CONFIG::ageWorker = 10;
    //    CONFIG["ageWorker"]=10;
    //    CONFIG["ageWarrior"]=15;
    //    CONFIG["lifeLarva"]= 10;
    //    CONFIG["lifeWorker"]= 10;
    //    CONFIG["lifeQueen"] = 15;
    //    CONFIG["consLarva"] = 1;
    //    CONFIG["consWorker"] = 2;
    //    CONFIG["consWarrior"] = 3;
    //    CONFIG["consQueen"] = 4;
}

/**
 * @brief Game::newRound
 * Init new round
 */
void Game::newRound()
{
    cout << "Game: New Round!" << endl;
}
