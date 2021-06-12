#include "egg.h"

Egg::Egg()
{
    _name = "";
    _currentAge = 0;
}

Egg::Egg(string name)
{
    _name = name;
    _currentAge = 0;
}

Egg::~Egg()
{
    //cout << "Oh no ! Egg " << _name << " died ! :-(" << endl;
}

void Egg::increaseAge()
{
    _currentAge++;
}

int Egg::getCurrentAge() const
{
    return _currentAge;
}

string Egg::getName() const
{
    return _name;
}
