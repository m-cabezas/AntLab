#include "queen.h"

Queen::Queen(CONFIG& config)
{
    _currentAge = config.ageWarrior;
    _maxHealth = config.lifeQueen;
    _foodCons = config.consQueen;
    _currentHealth = config.lifeQueen;
}

Queen::~Queen()
{
    //cout << "London Bridge is Down! Our beloved Queen passed away this morning... She was " << _currentAge << " years old." << endl;
}
