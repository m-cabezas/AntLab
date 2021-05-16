#include "larva.h"

Larva::Larva()
{

}

Larva::Larva(CONFIG &config, string name)
{
    _name = name;
    _currentAge = config.ageLarva;
    _maxHealth = config.lifeLarva;
    _foodCons = config.consLarva;
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

