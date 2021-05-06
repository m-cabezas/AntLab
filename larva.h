#ifndef LARVA_H
#define LARVA_H

#include "egg.h"
#include "util.h"

class Larva : public Egg
{
public:

    Larva();
    Larva(string name = "truc", int age = 5);
    ~Larva();

    //Methods
    void increaseAge();
    void heal(int foodNumber);
    void starve();
    //Getters
    int getCurrentAge();
    int getCurrentHealth();

protected:
    //Attributs
    int _foodCons;

};

#endif // LARVA_H
