#ifndef FOODSPAWNER_H
#define FOODSPAWNER_H

#include <iostream>
#include "obstacle.h"

class FoodSpawner : public Obstacle
{
public:
    //Methods
    FoodSpawner();
    FoodSpawner(int maxQuantity, pair<int,int> position, int width, int height);
    ~FoodSpawner();
    void doRound();
    int getCurrentQuantity() const;
    void decreaseQuantity(int quantity);
private:
    //Attributs
    int _maxQuantity;
    int _currentQuantity;

    //Methods
    int RandomFood();

};

#endif // FOODSPAWNER_H
