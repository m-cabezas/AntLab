#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <vector>

#include "anthill.h"
#include "foodSpawner.h"
#include "obstacle.h"

using namespace std;

class Environment
{

public:
    Environment();
    ~Environment();

    void initEnv();
    void addWorker(string name);
    void doRound();

private:
    pair <int, int> dimension;
    vector<vector<bool>> board;

    Anthill createAnthill();
    FoodSpawner createFoodSpawner();
    Obstacle createObstacle();
    void initWarriors();

};

#endif // ENVIRONMENT_H
