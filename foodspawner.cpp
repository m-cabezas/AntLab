#include "foodspawner.h"

//PUBLIC
/***
 * @brief default constructor of food spawner
 */
FoodSpawner::FoodSpawner()
{

}

/***
 * @brief main constructor of food spawner
 * @param maxQuantity
 * @param position
 * @param width
 * @param height
 */
FoodSpawner::FoodSpawner(int maxQuantity, pair<int,int> position, int width, int height)
{
    _maxQuantity = maxQuantity;
    _currentQuantity = rand() % maxQuantity + 50;
    _position = position;
    _width = width;
    _height = height;
}

/***
 * @brief default destructor of food spawner
 */
FoodSpawner::~FoodSpawner()
{

}

/***
 * @brief all actions that are done in a round by the food spawner
 */
void FoodSpawner::doRound()
{
    int spawnProb = rand() % 5;
    if (spawnProb == 1)
    {
        randomFood();
    }
}

/***
 * @brief method used to access food quantity of the food spawner
 * @return return the food quantity with an int
 */
int FoodSpawner::getCurrentQuantity() const
{
    return _currentQuantity;
}

/***
 * @brief method used to decrease the quantity of food contained by the food spawner
 * @param quantity
 */
void FoodSpawner::decreaseQuantity(int quantity)
{
    _currentQuantity -= quantity;
}

//PRIVATE
/***
 * @brief method used to create random quantity of food inside the food spawner
 */
void FoodSpawner::randomFood()
{
    _currentQuantity += rand() % 50 + 0;
    if (_currentQuantity > _maxQuantity)
    {
        _currentQuantity = _maxQuantity;
    }

}
