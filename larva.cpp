#include "larva.h"

Larva::Larva()
{

}

Larva::Larva(string name, int age) :
{
    _name = name;
    _currentAge = age;
//    _currentAge = CONFIG["ageLarva"];
//    _maxHealth = CONFIG["lifeLarva"];
//    _foodCons = CONFIG["consLarva"];
    _currentAge  = CONFIG::ageWorker;
}

Larva::~Larva()
{

}

void Larva::increaseAge()
{
    _currentAge++;
}

void Larva::heal(int foodNumber)
{
    _currentHealth += foodNumber;
    if(_currentHealth > _maxHealth) {
        _currentHealth = _maxHealth;
    }
}

/**
 * @brief Larva::starve reduce the life of the ant according to its food consumption
 */
void Larva::starve(){
    _currentHealth -= _foodCons;
}

// GETTERS

int Larva::getCurrentAge()
{
    return _currentAge;
}

int Larva::getCurrentHealth(){
    return _currentHealth;
}

