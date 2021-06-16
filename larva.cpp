#include "larva.h"

/***
 * @brief default constructor of larva
 */
Larva::Larva() {

}

/***
 * @brief main constructor of larva
 * @param config
 * @param name
 */
Larva::Larva(CONFIG &config, string name) {
    _name = name;
    _currentAge = config.ageLarva;
    _maxHealth = config.lifeLarva;
    _foodCons = config.consLarva;
    _currentHealth = config.lifeLarva;
}

/***
 * @brief default destructor of larva
 */
Larva::~Larva() {
}

/***
 * @brief method used to increase the life of a larva based on the food quantity it eat
 * @param foodNumber
 */
void Larva::heal(int foodNumber) {
    _currentHealth += foodNumber;
    if (_currentHealth > _maxHealth) {
        _currentHealth = _maxHealth;
    }
}

/**
 * @brief Larva::starve reduce the life of the ant according to its food consumption
 */
void Larva::starve() {
    _currentHealth -= _foodCons;
    if (_currentHealth < 0) {
        _currentHealth = 0;
    }
}

// GETTERS
/***
 * @brief method used to get the current health level of the larva
 * @return return the current health level as an int
 */
int Larva::getCurrentHealth() const {
    return _currentHealth;
}

