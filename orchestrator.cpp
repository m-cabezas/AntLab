#include "orchestrator.h"

Orchestrator::Orchestrator()
{

}
Orchestrator::Orchestrator(CONFIG config)
{
    _config = config;
    _dimension = pair<int, int>(100,50);
    // Initializing the grid
    _grid.resize(_dimension.first);
    for (unsigned int i = 0; i < _grid.size(); i++)
    {
        _grid.at(i).resize(_dimension.second);
    }

}

Orchestrator::~Orchestrator()
{

}

void Orchestrator::initOrch(CONFIG config)
{
    cout << "\t- Init Orchestrator : Environment of size x=" << _dimension.first << " y="<<_dimension.second << endl;
    _config = config;    
    pair <int,int> anthillPosition (_dimension.first/2,_dimension.second/2);
    createAnthill(anthillPosition);
    initFoodSpawners(_config.nbFoodSpawnerInit);
    initObstacles(_config.nbObstacleInit);
}

void Orchestrator::doRound()
{

}

void Orchestrator::createAnthill(pair <int,int> position)
{
    cout << "\t\t* Creating Anthill at : x=" << position.first << " y=" << position.second  << endl;
    Anthill *anthill = new Anthill(_config, _config.maxPopAnthill, _config.maxFoodAnthill, position, 1, 1);
    _anthills.push_back(anthill);
}

void Orchestrator::createFoodSpawner(pair <int,int> position)
{
    FoodSpawner *foodSpawner = new FoodSpawner(_config.maxFoodFoodSpawner, position, 1, 1);
    _foodSpawners.push_back(foodSpawner);
}

void Orchestrator::initFoodSpawners(int nbFoodSpawnerInit)
{
    cout << "\t\t* Creating FoodSpawners" << endl;
    for (int i = 0;i < nbFoodSpawnerInit;i++) {
        pair <int,int> foodSpawnerPosition = getFreePositions().at(rand() % getFreePositions().size() + 0);
        createFoodSpawner(foodSpawnerPosition);
    }
}

void Orchestrator::createObstacle(pair <int,int> position)
{
    Obstacle *obstacle = new Obstacle(position, 1, 1);
    _obstacles.push_back(obstacle);
}

void Orchestrator::initObstacles(int nbObstacleInit)
{
    cout << "\t\t* Creating obstacles" << endl;
    for (int i = 0;i < nbObstacleInit;i++) {
        pair <int,int> obstaclePosition = getFreePositions().at(rand() % getFreePositions().size() + 0);
        createObstacle(obstaclePosition);
        setCaseTaken(obstaclePosition.first, obstaclePosition.second, true);
    }
}

void Orchestrator::initWarriors(int nbWarriorInit, Anthill &anthill)
{

}

void Orchestrator::createWarrior(Anthill &anthill)
{
    string name = "warrior" + to_string(_warriors.size());
    Warrior *warrior = new Warrior(_config, name, anthill);
    _warriors.push_back(warrior);
}

vector<pair <int, int>> Orchestrator::getFreePositions()
{
    vector<pair <int, int>> freePositions;

    for (int x = 0;x < _dimension.first;x++) {
        for (int y = 0;y < _dimension.second;y++) {
            if (_grid.at(x).at(y) == false) {
                pair <int,int> freePosition (x,y);
                freePositions.push_back(freePosition);
            }
        }
    }

    return freePositions;
}

bool Orchestrator::checkPosition(int x, int y)
{
    if((x < _dimension.first && x >= 0) && (y < _dimension.second && y >= 0))
    {
        return _grid.at(x).at(y);
    } else {
        return false;
    }

}

void Orchestrator::setCaseTaken(int x, int y, bool taken)
{
    _grid.at(x).at(y) = taken;
}