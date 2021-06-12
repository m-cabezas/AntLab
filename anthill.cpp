#include "anthill.h"

Anthill::Anthill()
{

}

Anthill::Anthill(CONFIG &config, int maxPop, int maxFood, pair<int,int> position, int width, int height)
{
    _config = config;
    _maxPop = maxPop;
    _maxFood = maxFood;
    _currentFood = 0;
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

int Anthill::getNewWarriors()
{
    return _newWarriors;
}

//PUBLIC
void Anthill::initAnthill()
{
//    _queen = new Queen(_config);
    cout << "Init anthill with : " << _config.nbEggInit << " eggs, " << _config.nbLarvaInit << " larvas  and " << _config.nbWorkerInit << " workers" << endl;
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

void Anthill::spawnEgg()
{
    cout << "spawn " << endl;
   int lucky =  rand() % 100;
   if (lucky == 1) {
       int newEggs = rand() % 5 + 0;
       //cout << "Today the Queen blessed us with " << newEggs <<" new eggs! Long live the Queen!" <<  endl;
       for (int i = 0; i < newEggs; i++)
       {
           createEgg();
       }
   }
}

void Anthill::doRound()
{
    _newWarriors = 0;
    doRoundQueen();
    doRoundEggs();
    doRoundLarvas();
    doRoundWorkers();
    spawnEgg();
}

//PRIVATE
/**
 * @brief Anthill::doRoundQueen Manage the Queen's round
 */
void Anthill::doRoundQueen()
{
//    _queen->increaseAge();
//    _queen->starve();
//    if(_queen->getCurrentHealth() <= 0) {
//        delete _queen;
//    }
}

/**
 * @brief Anthill::doRoundEggs Manage eggs age for a round
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
            //cout << "grow "<<_eggs[i]->getName() << " i = " << i << endl;
//            growingEggs.push_back(i);
            growUpToLarva(_eggs[i]);
//            _eggs.erase(_eggs.begin()+i);
        } else {
            newEggs.push_back(_eggs[i]);
        }
        //cout << _eggs[i]->getName() << endl;
    }

    _eggs.clear();
    _eggs = newEggs;
    //cout << "end eggs" << endl;
}

/**
 * @brief Anthill::doRoundLarvas Manage larvas round
 */
void Anthill::doRoundLarvas()
{
    // Larvas treatment
    vector<Larva *> newLarvas;
    bool added = false;
    for(unsigned int i = 0 ; i < _larvas.size(); i++)
    {
        added = false;
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
//            growingLarvas.push_back(i);
            growUpToWorker(_larvas[i]);
//            _larvas.erase(_larvas.begin()+i);
        } else {
            newLarvas.push_back(_larvas[i]);
        }
        // If the ant is at half is life, we give food to it if possible
        if(_larvas[i]->getCurrentHealth() <= (_config.lifeLarva/2))
        {
            if(_currentFood > 0 ) {
                int heal = rand() % _currentFood + 0;
                _larvas[i]->heal(foodCons(heal));
                _currentFood -= heal;
            }
        }

    }
    _larvas.clear();
    _larvas = newLarvas;
            //    for(unsigned int i = 0 ; i < growingLarvas.size(); i++) {
//        growUpToWorker(_larvas[growingLarvas[i]]);
//        _larvas.erase(_larvas.begin()+growingLarvas[i]);
//    }
}

/**
 * @brief Anthill::doRoundWorkers manage workers round
 */
void Anthill::doRoundWorkers()
{
    vector<Worker *> newWorkers;
    for(unsigned int i = 0 ; i < _workers.size(); i++)
    {
        //cout << "workers round" << endl;
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
                _currentFood -= heal;
            }            
        }

    }
    _workers.clear();
    _workers = newWorkers;
}

void Anthill::growUpToLarva(Egg* egg)
{
    Anthill::createLarva();
    //cout << "Egg " << egg->getName() << " is becoming a larva! We're so proud of it!" << endl;
    delete egg;

}

void Anthill::growUpToWorker(Larva* larva)
{
    Anthill::createWorker();
    //cout << "Larva " << larva->getName() << " is becoming a worker! We're so proud of it!" << endl;
    delete larva;
}

void Anthill::growUpToWarrior(Worker* worker)
{
    _newWarriors += 1;
    //cout << "Warrior " << worker->getName() << " is becoming a warrior! We're so proud of it!" << endl;
    delete worker;
}

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

int Anthill::foodCons(int desiredFood)
{
    int availableCons = 0;
    if(_currentFood == 0 )
    {
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
