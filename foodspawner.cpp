#include "foodspawner.h"

//PUBLIC
FoodSpawner::FoodSpawner()
{

}

FoodSpawner::FoodSpawner(int maxQuantity, pair<int,int> position, int width, int height)
{
    _maxQuantity = maxQuantity;
    _currentQuantity = rand() % maxQuantity + 0;
    _position = position;
    _width = width;
    _height = height;
}

FoodSpawner::~FoodSpawner()
{

}

void FoodSpawner::doRound()
{
    int spawnProb = rand() % 10;
    if (spawnProb == 1)
    {
        randomFood();
    }
}

int FoodSpawner::getCurrentQuantity() const
{
    return _currentQuantity;
}

void FoodSpawner::decreaseQuantity(int quantity)
{
    _currentQuantity -= quantity;
}

//PRIVATE
void FoodSpawner::randomFood()
{
    _currentQuantity += rand() % 10 + 0;
    if (_currentQuantity > _maxQuantity)
    {
        _currentQuantity = _maxQuantity;
    }

}
