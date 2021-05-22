#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <iostream>
#include <vector>


#include "foodspawner.h"
#include "obstacle.h"
#include "warrior.h"
#include "util.h"
#include "anthill.h"

using namespace std;

class Orchestrator
{

public:
    //Methods
    Orchestrator();
    Orchestrator(CONFIG config);
    ~Orchestrator();

    void initOrch(CONFIG config);
    void doRound();

private:
    //Attibuts
    CONFIG _config;
    pair <int, int> _dimension;
    vector<vector<bool>> _grid;
    vector<Warrior *> _warriors;
    vector<Obstacle *> _obstacles;
    vector<FoodSpawner *> _foodSpawners;
    vector<Anthill *> _anthills;

    //Methods
    void createAnthill(pair<int,int> position);
    void createFoodSpawner(pair<int,int> position);
    void initFoodSpawners(int nbFoodSpawnerInit);
    void createObstacle(pair <int,int> position);
    void initObstacles(int nbObstacleInit);
    void createWarrior(Anthill &anthill);
    void initWarriors(int nbWarriorInit, Anthill &anthill);
    void setCaseTaken(int x, int y, bool taken);

    vector<pair <int, int>> getFreePositions();
    bool checkPosition(int x, int y);

};

#endif // ORCHESTRATOR_H
