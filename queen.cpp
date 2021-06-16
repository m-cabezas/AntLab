#include "queen.h"

Queen::Queen()
{

}

/***
 * @brief main constructor of queen
 * @param config
 */
Queen::Queen(CONFIG& config)
{
    _currentAge = config.ageWarrior;
    _maxHealth = config.lifeQueen;
    _foodCons = config.consQueen;
    _currentHealth = config.lifeQueen;
    _name = "Queen";
}

/***
 * @brief default destructor of queen
 */
Queen::~Queen()
{
    //cout << "London Bridge is Down! Our beloved Queen passed away this morning... She was " << _currentAge << " years old." << endl;
}
