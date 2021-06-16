#ifndef EGG_H
#define EGG_H

#include <iostream>
#include "util.h"

using namespace std;

class Egg {
public:
    //Methods
    Egg();

    Egg(string name);

    ~Egg();

    void increaseAge();

    int getCurrentAge() const;

    string getName() const;

private:

protected:
    //Attributes
    string _name;
    int _currentAge;
};

#endif // EGG_H
