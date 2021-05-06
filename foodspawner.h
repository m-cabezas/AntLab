#ifndef FOODSPAWNER_H
#define FOODSPAWNER_H
#include <iostream>

class FoodSpawner
{
private:
    int maxQuantity;
    int currentQuantity;
    int RandomFood();
public:
    FoodSpawner();
    void DoRound();
};

#endif // FOODSPAWNER_H
