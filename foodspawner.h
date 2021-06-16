#ifndef FOODSPAWNER_H
#define FOODSPAWNER_H

#include <iostream>
#include "obstacle.h"

class FoodSpawner : public Obstacle {
public:
    //Methods
    FoodSpawner();

    FoodSpawner(int maxQuantity, pair<int, int> position, int width, int height);

    ~FoodSpawner();

    void doRound();

    int getCurrentQuantity() const;

    void decreaseQuantity(int quantity);

private:
    //Attributes
    int _maxQuantity;
    int _currentQuantity;

    //Methods
    void randomFood();

};

#endif // FOODSPAWNER_H
