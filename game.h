#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include <iostream>
#include "environment.h"
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


    CONFIG _config;
    //Attributs
    Environment _environment;

    //Methods
    void newRound();
};

#endif // GAME_H
