#include "anthill.h"

/***
 * @brief default constructor of anthill
 */
Anthill::Anthill()
{

}

/**
 * @brief main constructor of Anthill
 * @param config
 * @param maxPop
 * @param maxFood
 * @param position
 * @param width
 * @param height
 */
Anthill::Anthill(CONFIG &config, int maxPop, int maxFood, pair<int,int> position, int width, int height)
{
    _config = config;
    _maxPop = maxPop;
    _maxFood = maxFood;
    _currentFood = 0;
    _position = position;
    _width = width;
    _height = height;
    _queen = new Queen(_config);

}

/***
 * @brief destructor of anthill
 */
Anthill::~Anthill()
{
    _eggs.erase(_eggs.begin(), _eggs.end());
    _larvas.erase(_larvas.begin(), _larvas.end());
    _workers.erase(_workers.begin(), _workers.end());
}

/***
 * @brief get all warriors that just evolved from workers
 * @return return warriors created by orchestrator
 */
int Anthill::getNewWarriors() const
{
    return _newWarriors;
}

/**
 * Gives the current population within the anthill
 * @return total population
 */
int Anthill::getPopulation() const
{
    return _eggs.size() + _larvas.size() + _workers.size();
}

//PUBLIC
/***
 * @brief create eggs, larvas, workers at first round
 */
void Anthill::initAnthill()
{
    cout << "Init anthill with : " << _config.nbEggInit << " eggs, " << _config.nbLarvaInit << " larvas  and " << _config.nbWorkerInit << " workers" << endl;
    _queenAlive = true;
    _currentFood = _config.maxFoodAnthill;
    for (int i = 0;  i < _config.nbEggInit; i++){
      Anthill::createEgg();
    }
    for (int i = 0;  i < _config.nbLarvaInit; i++){
      Anthill::createLarva();
    }
    for (int i = 0;  i < _config.nbWorkerInit; i++){
      Anthill::createWorker();
    }
}

/***
 * @brief method used to spawn eggs in the anthill, between 0 and 5 eggs are created
 */
void Anthill::spawnEgg()
{    
   default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> distrib{0,6};
   int lucky =  distrib(re);
   if (lucky == 1) {
       uniform_int_distribution<int> distrib{0,9};
       int newEggs = distrib(re);
       for (int i = 0; i < newEggs; i++)
       {
           createEgg();
       }
   }
}

/***
 * @brief contain all Anthill actions for a round
 */
void Anthill::doRound()
{    
    _newWarriors = 0;
    doRoundQueen();
    doRoundEggs();
    doRoundLarvas();
    doRoundWorkers();
    cout << "Available food in anthill: "  << _currentFood << endl;
    cout << "Eggs number: "  << _eggs.size() << endl;
    cout << "Larvas number: "  << _larvas.size() << endl;
    cout << "Worker number: "  << _workers.size() << endl;
}

//PRIVATE
/**
 * @brief manage the Queen's round
 */
void Anthill::doRoundQueen()
{
    if(_queenAlive) {
        _queen->increaseAge();
        _queen->starve();

        if(_queen->getCurrentHealth() <= 0) {
            delete _queen;
            _queenAlive = false;
            return;
        }
        // If the ant is at half is life, we give food to it if possible
        if(_queen->getCurrentHealth() <= (_config.lifeQueen/2))
        {
            if(_currentFood > 0 ) {
                int heal = rand() % _currentFood + 0;
                _queen->heal(foodCons(heal));
            }
        }
    }
}

/**
 * @brief manage eggs age for a round
 */
void Anthill::doRoundEggs()
{
    vector<Egg *> newEggs;
    for(unsigned int i = 0 ; i < _eggs.size(); i++)
    {
        _eggs[i]->increaseAge();

        // If the ant has to grow, we add its index to the growing list and we go to the next ant
        if(_eggs[i]->getCurrentAge() == _config.ageLarva)
        {
            growUpToLarva(_eggs[i]);
        } else {
            newEggs.push_back(_eggs[i]);
        }
    }

    _eggs.clear();
    _eggs = newEggs;
    //cout << "end eggs" << endl;
}

/**
 * @brief manage larvas round
 */
void Anthill::doRoundLarvas()
{
    // Larvas treatment
    vector<Larva *> newLarvas;
    for(unsigned int i = 0 ; i < _larvas.size(); i++)
    {
        _larvas[i]->increaseAge();
        _larvas[i]->starve();
        // If the ant is not dead, we add it to the new ant list
        if(_larvas[i]->getCurrentHealth() <= 0)
        {
            delete _larvas[i];
            continue;
        }
        // If the ant has to grow, we add its index to the growing list and we go to the next ant
        if(_larvas[i]->getCurrentAge() == _config.ageWorker)
        {
            growUpToWorker(_larvas[i]);
        } else {
            newLarvas.push_back(_larvas[i]);
        }
        // If the ant is at half is life, we give food to it if possible
        if(_larvas[i]->getCurrentHealth() <= (_config.lifeLarva/2))
        {
            if(_currentFood > 0 ) {
                int heal = rand() % _currentFood + 0;
                _larvas[i]->heal(foodCons(heal));
            }
        }

    }
    _larvas.clear();
    _larvas = newLarvas;
}

/**
 * @brief manage workers round
 */
void Anthill::doRoundWorkers()
{
    vector<Worker *> newWorkers;
    for(unsigned int i = 0 ; i < _workers.size(); i++)
    {
        _workers[i]->increaseAge();
        _workers[i]->starve();
        // If the ant is not dead, we add it to the new ant list
        if(_workers[i]->getCurrentHealth() <= 0)
        {
            delete _workers[i];
            continue;
        }
        // If the ant has to grow, we add its index to the growing list and we go to the next ant
        if(_workers[i]->getCurrentAge() == _config.ageWarrior)
        {
            growUpToWarrior(_workers[i]);
        } else {
            newWorkers.push_back(_workers[i]);
        }
        // If the ant is at half is life, we give food to it if possible
        if(_workers[i]->getCurrentHealth() <= (_config.lifeLarva/2))
        {
            if(_currentFood > 0 ) {
                int heal = rand() % _currentFood + 0;
                _workers[i]->heal(foodCons(heal));
            }            
        }

    }
    _workers.clear();
    _workers = newWorkers;
}

/***
 * @brief method used by the anthill to grow egg to larva
 * @param egg
 */
void Anthill::growUpToLarva(Egg* egg)
{
    Anthill::createLarva();
    //cout << "Egg " << egg->getName() << " is becoming a larva! We're so proud of it!" << endl;
    delete egg;

}

/***
 * @brief method used by the anthill to grow larva to worker
 * @param larva
 */
void Anthill::growUpToWorker(Larva* larva)
{
    Anthill::createWorker();
    //cout << "Larva " << larva->getName() << " is becoming a worker! We're so proud of it!" << endl;
    delete larva;
}

/***
 * @brief method used by the anthill to grow worker to warrior
 * @param worker
 */
void Anthill::growUpToWarrior(Worker* worker)
{
    _newWarriors += 1;
    //cout << "Warrior " << worker->getName() << " is becoming a warrior! We're so proud of it!" << endl;
    delete worker;
}

/***
 * @brief method used by anthill that is called by the warrior to increase food quantity via la méthode giveFood
 * @param foodQuantity
 */
void Anthill::addFood(int foodQuantity)
{
    _currentFood += foodQuantity;
    if (_currentFood > _maxFood)
    {
        _currentFood = _maxFood;
    }
    //cout << "Anthill recived "<< foodQuantity <<" of food! ----------------------------------" << endl;
    //cout << "\t * New Food quantity : " << _currentFood <<"/" << _maxFood << endl;
}

//PRIVATE
/***
 * @brief method used by the anthill to create one egg
 */
void Anthill::createEgg()
{
    string name = "egg" + to_string(_eggs.size());
    Egg *egg = new Egg(name);
    _eggs.push_back(egg);
}

/***
 * @brief method used by the anthill to create one larva
 */
void Anthill::createLarva()
{
    string name = "larva" + to_string(_larvas.size());
    Larva *larva = new Larva(_config, name);
    _larvas.push_back(larva);
}

/***
 * @brief method used by the anthill to create one worker
 */
void Anthill::createWorker()
{
    string name = "worker" + to_string(_workers.size());
    Worker *worker = new Worker(_config, name);
    _workers.push_back(worker);
}

/***
 * @brief method used by the anthill to manage food consumed by the warriors
 * @param desiredFood
 * @return available food quantity that can be consumed as an int
 */
int Anthill::foodCons(int desiredFood)
{
    int availableCons = 0;
    if(_currentFood <= 0 )
    {
        _currentFood = 0;
        return 0;
    }
    if(desiredFood > _currentFood)
    {
        availableCons = _currentFood;
        _currentFood = 0;
    } else if(desiredFood <= _currentFood)
    {
        _currentFood -= desiredFood;
        availableCons = desiredFood;
    }

    return availableCons;
}

bool Anthill::isQueenAlive()
{
    return _queenAlive;
}
