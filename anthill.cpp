#include "anthill.h"

Anthill::Anthill()
{

}

Anthill::Anthill(CONFIG &config, int maxPop, int maxFood, pair<int,int> position, int width, int height)
{
    _config = config;
    _maxPop = maxPop;
    _maxFood = maxFood;
    this->position = position;
    this->width = width;
    this->height = height;
}

Anthill::~Anthill()
{
    _eggs.erase(_eggs.begin(), _eggs.end());
    _larvas.erase(_larvas.begin(), _larvas.end());
    _workers.erase(_workers.begin(), _workers.end());
}

//PUBLIC
void Anthill::initAnthill()
{
    Anthill::createEgg();
    Anthill::createLarva();
    Anthill::createWorker();
}

void Anthill::spawnEgg()
{

}

void Anthill::doRound()
{

}

void Anthill::growUpToLarva(Egg egg)
{
    Anthill::createLarva();
    egg.~Egg();
}

void Anthill::growUpToWorker(Larva larva)
{
    Anthill::createWorker();
    larva.~Larva();
}

void Anthill::growUpToWarrior(Worker worker)
{

}

void Anthill::addFood(int foodQuantity)
{
    _currentFood += foodQuantity;
    if (_currentFood > _maxFood)
    {
        _currentFood = _maxFood;
    }
    cout << "Anthill recived food! " << endl;
    cout << "\t * New Food quantity : " << _currentFood <<"/" << _maxFood << endl;
}

//PRIVATE
void Anthill::createEgg()
{
    string name = "egg" + to_string(_eggs.size());
    Egg *egg = new Egg(name);
    _eggs.push_back(egg);
}

void Anthill::createLarva()
{
    string name = "larva" + to_string(_larvas.size());
    Larva *larva = new Larva(_config, name);
    _larvas.push_back(larva);
}

void Anthill::createWorker()
{
    string name = "worker" + to_string(_workers.size());
    Worker *worker = new Worker(_config, name);
    _workers.push_back(worker);
}
