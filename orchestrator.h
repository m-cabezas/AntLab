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
    Orchestrator(CONFIG &config);
    ~Orchestrator();

    void initEnv();
    void addWorker(string name);
    void doRound();
    bool checkPosition(int x, int y);

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
    Anthill& createAnthill();
    FoodSpawner& createFoodSpawner();
    Obstacle createObstacle();
    void initWarriors();
    void createWarrior(Anthill &anthill);

};

#endif // ORCHESTRATOR_H
