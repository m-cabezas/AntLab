#ifndef EGG_H
#define EGG_H

#include <iostream>
#include "util.h"

using namespace std;

class Egg
{
public:
    Egg();
    Egg(string name);
    ~Egg();

private:


protected:
    //Attributs
    string _name;
    int _currentAge;
};

#endif // EGG_H
