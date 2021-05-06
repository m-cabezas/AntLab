#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <vector>

#include "anthill.h"
#include "foodspawner.h"
#include "obstacle.h"
#include "warrior.h"

using namespace std;

class Environment
{

public:
    //Methods
    Environment();
    ~Environment();

    void initEnv();
    void addWorker(string name);
    void doRound();

private:
    //Attibuts
    pair <int, int> _dimension;
    vector<vector<bool>> _board;
    vector<Warrior> _warriors;
    vector<Obstacle> _obstacles;
    vector<FoodSpawner> _foodSpawners;

    //Methods
    Anthill& createAnthill();
    FoodSpawner& createFoodSpawner();
    Obstacle createObstacle();
    void initWarriors();

};

#endif // ENVIRONMENT_H