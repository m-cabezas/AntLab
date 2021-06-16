#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "orchestrator.h"
#include "util.h"

using namespace std;

class Game
{
public:
    //Methods
    Game();
    ~Game();

    void initializeGrid();
    void initGame();
    CONFIG getConfig();

private:
    //Attributes
    CONFIG _config;
    Orchestrator * _orchestrator;

    //Methods
    bool newRound(int roundNumber);
    void doRounds();
};
#endif // GAME_H
