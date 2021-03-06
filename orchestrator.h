#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>


#include "foodspawner.h"
#include "obstacle.h"
#include "warrior.h"
#include "util.h"
#include "anthill.h"

using namespace std;

class Orchestrator {

public:
    //Methods
    Orchestrator();

    Orchestrator(CONFIG config);

    ~Orchestrator();

    pair<int, int> getDimension() const;

    int getMapEntity(int x, int y);

    void initOrch(CONFIG config);

    int doRound();

private:
    //Attributes
    CONFIG _config;
    pair<int, int> _dimension;
    vector <vector<bool>> _grid;
    vector <vector<bool>> _obstaclesGrid;
    vector <vector<bool>> _foodSpawnersGrid;
    vector <vector<bool>> _anthillsGrid;
    vector<Warrior *> _warriors;
    vector<Obstacle *> _obstacles;
    vector<FoodSpawner *> _foodSpawners;
    vector<Anthill *> _anthills;

    //Methods
    void createAnthill(pair<int, int> position, bool init);

    void createFoodSpawner(pair<int, int> position);

    void initFoodSpawners(int nbFoodSpawnerInit);

    void createObstacle(pair<int, int> position);

    void initObstacles(int nbObstacleInit);

    void createWarrior(pair<int, int> position, Anthill *anthill);

    void initWarriors(int nbWarriorInit, Anthill *anthill);

    void setCaseTaken(int x, int y, bool taken);

    bool isCaseTaken(int x, int y);

    bool isNextTo(int antX, int antY, int objX, int objY);

    vector <pair<int, int>> getFreePositions();

    vector <pair<int, int>> getForbiddenPositions(int x, int y);

    FoodSpawner *checkFoodNearby(int x, int y);

    bool checkPosition(int x, int y);

    vector <pair<int, int>> getWarriorsFreePositions(Anthill &anthill);

};

#endif // ORCHESTRATOR_H
