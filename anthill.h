#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include "obstacle.h"
#include "util.h"
#include "larva.h"
#include "worker.h"
#include "egg.h"

class Anthill : public Obstacle
{
public: 
    //Attributs


    //Methods
    Anthill();
    Anthill(CONFIG &config, int maxPop, int maxFood, pair<int,int> position, int width, int height);
    ~Anthill();
    void initAnthill();
    void spawnEgg();
    void doRound();
    void growUpToLarva(Egg egg);
    void growUpToWorker(Larva larva);
    void growUpToWarrior(Worker worker);

private:
    //Attibuts
    CONFIG _config;
    int _maxPop;
    int _maxFood;
    vector<Egg *> _eggs;
    vector<Larva *> _larvas;
    vector<Worker *> _workers;

    //Methods
    void createEgg();
    void createLarva();
    void createWorker();


};

#endif // ANTHILL_H
