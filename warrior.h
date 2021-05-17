#ifndef WARRIOR_H
#define WARRIOR_H


#include "worker.h"
#include "anthill.h"

class Warrior : public Worker
{
public:
    //Methods
    Warrior();
    Warrior(CONFIG &config, string name, Anthill &anthill);
    ~Warrior();

    void explore();
    void returnToAnthill();
    void takeFood();
    void attack();
    void giveFood();

private:
    //Attributs
    int _foodCapacity;
    int _currentFood;
    int _mode;
    pair<int,int> _position;
    pair<int,int> _prevPos;
    CONFIG _config;
    Anthill _anthill;

};

#endif // WARRIOR_H
