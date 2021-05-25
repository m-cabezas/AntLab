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
    initWarriors(_config.nbWarriorInit, *_anthills[0]);
}

void Orchestrator::doRound()
{

    for(unsigned int i = 0 ; i < _warriors.size(); i++)
    {
        pair<int,int> postion = _warriors[i]->getPosition();
        _warriors[i]->explore(getForbidenPositions(postion.first, postion.second));
    }
}

void Orchestrator::createAnthill(pair <int,int> position)
{
    cout << "\t\t* Creating Anthill at : x=" << position.first << " y=" << position.second  << endl;
    Anthill *anthill = new Anthill(_config, _config.maxPopAnthill, _config.maxFoodAnthill, position, 1, 1);
    _anthills.push_back(anthill);
    setCaseTaken(position.first, position.second, true);
}

void Orchestrator::createFoodSpawner(pair <int,int> position)
{
    cout << "\t\t* Creating FoodSpawner at : x=" << position.first << " y=" << position.second  << endl;
    FoodSpawner *foodSpawner = new FoodSpawner(_config.maxFoodFoodSpawner, position, 1, 1);
    _foodSpawners.push_back(foodSpawner);
    setCaseTaken(position.first, position.second, true);
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
    cout << "\t\t* Creating Obstacle at : x=" << position.first << " y=" << position.second  << endl;
    Obstacle *obstacle = new Obstacle(position, 1, 1);
    _obstacles.push_back(obstacle);
    setCaseTaken(position.first, position.second, true);
}

void Orchestrator::initObstacles(int nbObstacleInit)
{
    cout << "\t\t* Creating obstacles" << endl;
    for (int i = 0;i < nbObstacleInit;i++) {
        pair <int,int> obstaclePosition = getFreePositions().at(rand() % getFreePositions().size() + 0);
        createObstacle(obstaclePosition);
    }
}

void Orchestrator::initWarriors(int nbWarriorInit, Anthill &anthill)
{
    cout << "\t\t* Creating warriors" << endl;
    for (int i = 0;i < nbWarriorInit;i++) {
        vector<pair <int,int>> warriorsFreePositions;
        vector<pair <int,int>> freePositions = getFreePositions();
        pair <int,int> anthillPosition = anthill.getPosition();
        vector<pair <int,int>> nearbyPositions{pair <int,int> (anthillPosition.first-1, anthillPosition.second), pair <int,int> (anthillPosition.first-1, anthillPosition.second-1), pair <int,int> (anthillPosition.first-1, anthillPosition.second+1), pair <int,int> (anthillPosition.first+1, anthillPosition.second), pair <int,int> (anthillPosition.first+1, anthillPosition.second-1), pair <int,int> (anthillPosition.first+1, anthillPosition.second+1), pair <int,int> (anthillPosition.first, anthillPosition.second-1), pair <int,int> (anthillPosition.first, anthillPosition.second+1)};
        for (int x = 0;x < int(freePositions.size());x++) {
            pair <int,int> freePosition = freePositions.at(x);
            for (int y = 0;y < int(nearbyPositions.size());y++) {
                pair <int,int> nearbyPosition = nearbyPositions.at(y);
                if (freePosition == nearbyPosition) {
                    warriorsFreePositions.push_back(freePosition);
                }
            }
        }
        if (!warriorsFreePositions.empty()) {
            pair <int,int> warriorPosition = warriorsFreePositions.at(rand() % warriorsFreePositions.size() + 0);
            createWarrior(warriorPosition, anthill);
        }
        else {
            cout << "\t\t* Unable to create warrior, no more positions available" << endl;
        }
    }
}

void Orchestrator::createWarrior(pair <int,int> position, Anthill &anthill)
{
    cout << "\t\t* Creating Warrior at : x=" << position.first << " y=" << position.second  << endl;
    string name = "warrior" + to_string(_warriors.size());
    Warrior *warrior = new Warrior(_config.capacityWarrior, position, name, anthill);
    _warriors.push_back(warrior);
    setCaseTaken(position.first, position.second, true);
}

vector<pair <int, int>> Orchestrator::getFreePositions()
{
    vector<pair <int, int>> freePositions;

    for (int x = 0;x < _dimension.first;x++) {
        for (int y = 0;y < _dimension.second;y++) {
            if (checkPosition(x,y) == false) {
                pair <int,int> freePosition (x,y);
                freePositions.push_back(freePosition);
            }
        }
    }

    return freePositions;
}

vector<pair<int,int>> Orchestrator::getForbidenPositions(int x, int y)
{
    vector<pair<int,int>> forbiddenPositions;
    if(!checkPosition(x-1,y))
    {
        pair<int,int> forbidden(x-1,y);
        forbiddenPositions.push_back(forbidden);
    }
    if(!checkPosition(x+1,y))
    {
        pair<int,int> forbidden(x+1,y);
        forbiddenPositions.push_back(forbidden);
    }
    if(!checkPosition(x,y-1))
    {
        pair<int,int> forbidden(x,y-1);
        forbiddenPositions.push_back(forbidden);
    }
    if(!checkPosition(x,y+1))
    {
        pair<int,int> forbidden(x,y+1);
        forbiddenPositions.push_back(forbidden);
    }
    return forbiddenPositions;
}

FoodSpawner Orchestrator::checkFoodNearby(int x, int y)
{

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
    if((x < _dimension.first && x >= 0) && (y < _dimension.second && y >= 0))
    {
        _grid.at(x).at(y) = taken;
    }
}
