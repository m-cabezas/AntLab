#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include <iostream>
#include "environment.h"

static std::map<string, int> CONFIG;

class Game
{

public:
    Game();
    ~Game();

    void initGame();


private:
    Environment environment;
    void newRound();
};

#endif // GAME_H
