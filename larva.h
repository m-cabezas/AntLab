#ifndef LARVA_H
#define LARVA_H

#include "egg.h"
#include "util.h"

class Larva : public Egg {
public:
    //Methods
    Larva();

    Larva(CONFIG &config, string name);

    ~Larva();

    void heal(int foodNumber);

    void starve();

    int getCurrentHealth() const;

protected:
    //Attributes
    int _foodCons;
    int _currentHealth;
    int _maxHealth;

};

#endif // LARVA_H
