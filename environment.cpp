#include "environment.h"

Environment::Environment()
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


