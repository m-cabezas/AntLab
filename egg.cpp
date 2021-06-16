#include "egg.h"

/***
 * @brief default constructor of egg
 */
Egg::Egg()
{
    _name = "";
    _currentAge = 0;
}

/***
 * @brief main constructor of egg
 * @param name
 */
Egg::Egg(string name)
{
    _name = name;
    _currentAge = 0;
}

/***
 * @brief default destructor of egg
 */
Egg::~Egg()
{
    //cout << "Oh no ! Egg " << _name << " died ! :-(" << endl;
}

/***
 * @brief method used by anthill to increase egg age
 */
void Egg::increaseAge()
{
    _currentAge++;
}

/***
 * @brief method used by anthill to get current age of the current egg
 * @return
 */
int Egg::getCurrentAge() const
{
    return _currentAge;
}

/***
 * @brief method used to get the name of the current egg
 * @return
 */
string Egg::getName() const
{
    return _name;
}
