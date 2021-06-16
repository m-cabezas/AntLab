#include "queen.h"

/**
 * @brief default constructor of queen
 */
Queen::Queen() {

}

/***
 * @brief main constructor of queen
 * @param config
 */
Queen::Queen(CONFIG &config) {
    _currentAge = config.ageWarrior;
    _maxHealth = config.lifeQueen;
    _foodCons = config.consQueen;
    _currentHealth = config.lifeQueen;
    _name = "Queen";
}

/***
 * @brief default destructor of queen
 */
Queen::~Queen() {

}
