#include "foodspawner.h"

//PUBLIC
FoodSpawner::FoodSpawner()
{

}

FoodSpawner::FoodSpawner(int maxQuantity, pair<int,int> position, int width, int height)
{
    _maxQuantity = maxQuantity;
    _currentQuantity = rand() % maxQuantity + 0;
    this->position = position;
    this->width = width;
    this->height = height;
}

FoodSpawner::~FoodSpawner()
{

}

void FoodSpawner::DoRound()
{

}

//PRIVATE
int FoodSpawner::RandomFood()
{
    return 0;
}
