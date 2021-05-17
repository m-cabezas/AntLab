#ifndef FOODSPAWNER_H
#define FOODSPAWNER_H

#include <iostream>
#include "obstacle.h"

class FoodSpawner : public Obstacle
{
private:
    //Attributs
    int _maxQuantity;
    int _currentQuantity;

    //Methods
    int RandomFood();

public:
    //Methods
    FoodSpawner();
    ~FoodSpawner();
    void DoRound();
};

#endif // FOODSPAWNER_H
