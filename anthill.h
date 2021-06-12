#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include "obstacle.h"
#include "util.h"
#include "larva.h"
#include "worker.h"
#include "egg.h"
//#include "queen.h"

class Anthill : public Obstacle
{
public: 
    //Attributs


    //Methods
    Anthill();
    Anthill(CONFIG &config, int maxPop, int maxFood, pair<int,int> position, int width, int height);
    ~Anthill();
    int getNewWarriors();

    void initAnthill();
    void spawnEgg();
    void doRound();    
    void addFood(int foodQuantity);

private:
    //Attibuts
    CONFIG _config;
    int _maxPop;
    int _maxFood;
    int _currentFood;
//    Queen* _queen;
    vector<Egg *> _eggs;
    vector<Larva *> _larvas;
    vector<Worker *> _workers;
    int _newWarriors;

    //Methods
    void doRoundQueen();
    void doRoundEggs();
    void doRoundLarvas();
    void doRoundWorkers();
    void growUpToLarva(Egg* egg);
    void growUpToWorker(Larva* larva);
    void growUpToWarrior(Worker* worker);
    void createEgg();
    void createLarva();
    void createWorker();
    int foodCons(int desiredFood);


};

#endif // ANTHILL_H
