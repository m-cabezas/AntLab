#ifndef ANTHILL_H
#define ANTHILL_H

#include "obstacle.h"
#include "util.h"
#include "environment.h"
#include "larva.h"
#include "worker.h"
#include "egg.h"

class Anthill : public Obstacle
{
public:

    Anthill(CONFIG &config, Environment &environment);
    ~Anthill();

    //Methods
    void initAnthill();
    void spawnEgg();
    void doRound();
    void growUp();

private:
    //Attibuts
    CONFIG _config;
    Environment _environment;
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
