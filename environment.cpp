#include "environment.h"

Environment::Environment()
{

}

Environment::Environment(CONFIG &config)
{

}

Environment::~Environment()
{

}

void Environment::initEnv()
{

}

void Environment::addWorker(string name)
{

}

void Environment::doRound()
{

}

bool Environment::checkPosition(int x, int y)
{
    if((x < _dimension.first && x >= 0) && (y < _dimension.second && y >= 0))
    {
        return _grid.at(x).at(y);
    } else {
        return false;
    }

}

Anthill& Environment::createAnthill()
{
    Anthill * anthill = new Anthill;
    return *anthill;
}

FoodSpawner& Environment::createFoodSpawner()
{
    FoodSpawner* foodSpawner = new FoodSpawner;
    return *foodSpawner;
}

Obstacle createObstacle()
{

};

void initWarriors()
{

};

void createWarrior()
{
    string name = "warrior" + to_string(_warriors.size());
    Worker *warrior = new Warrior(_config, name);
    _warriors.push_back(warrior);
}
};


