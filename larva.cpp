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
    _currentHealth = config.lifeLarva;
}

Larva::~Larva()
{
    cout << "Oh no ! Larva " << _name << " died ! :-(" << endl;
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
    if(_currentHealth < 0) {
        _currentHealth = 0;
    }
}

// GETTERS
int Larva::getCurrentHealth() const
{
    return _currentHealth;
}

