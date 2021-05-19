#ifndef LARVA_H
#define LARVA_H

#include "egg.h"
#include "util.h"

class Larva : public Egg
{
public:

    Larva();
    Larva(CONFIG &config, string name);
    ~Larva();

    //Methods
    void increaseAge();
    void heal(int foodNumber);
    void starve();
    //Getters
    int getCurrentAge() const;
    int getCurrentHealth() const;

protected:
    //Attributs
    int _foodCons;
    int _currentHealth;
    int _maxHealth;

};

#endif // LARVA_H
