#ifndef WARRIOR_H
#define WARRIOR_H

#include "worker.h"
#include "anthill.h"

class Warrior : public Worker
{
public:
    //Methods
    Warrior();
    Warrior(int capacityWarrior, pair<int,int> position, string name, Anthill &anthill);
    ~Warrior();

    const pair<int,int> getPosition();
    void explore(vector<pair<int,int>> forbiddenPositions);
    void returnToAnthill(vector<pair<int,int>> forbiddenPositions);
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
    Anthill _anthill;

    //Methods
    bool checkPosition(vector<pair<int,int>> forbiddenPositions, int posX, int posY);
    pair<int,int> getRandomPos(vector<pair<int, int>> forbiddenPositions, int prevX, int prevY, int posX, int posY);

};

#endif // WARRIOR_H
