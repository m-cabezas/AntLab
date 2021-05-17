#include "orchestrator.h"

Orchestrator::Orchestrator(CONFIG &config)
{
    _config = config;
}

Orchestrator::~Orchestrator()
{

}

void Orchestrator::initOrch()
{

}

void Orchestrator::addWorker(string name)
{

}

void Orchestrator::doRound()
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

Anthill& Orchestrator::createAnthill()
{
    Anthill *anthill = new Anthill(_config);
    return *anthill;
}

FoodSpawner& Orchestrator::createFoodSpawner()
{
    FoodSpawner* foodSpawner = new FoodSpawner;
    return *foodSpawner;
}

Obstacle Orchestrator::createObstacle()
{

};

void Orchestrator::initWarriors()
{

};

void Orchestrator::createWarrior(Anthill &anthill)
{
    string name = "warrior" + to_string(_warriors.size());
    Warrior *warrior = new Warrior(_config, name, anthill);
    _warriors.push_back(warrior);
};


