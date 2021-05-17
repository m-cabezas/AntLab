#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include <iostream>
#include "orchestrator.h"
#include "util.h"

class Game
{

public:
    //Methods
    Game();
    ~Game();

    void initGame();
    CONFIG getConfig();


private:

    //Attributs
    CONFIG _config;
    Orchestrator _orchestrator;

    //Methods
    void newRound();
};

#endif // GAME_H
