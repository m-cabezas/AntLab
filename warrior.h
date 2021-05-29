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
    int takeFood(int availableQuantity);
    void attack();
    int giveFood();
    int getMode() const;

private:
    //Attributs
    int _foodCapacity; // the maximum food the ant can carry
    int _currentFood; // The food the ant is carrying
    int _mode;
    pair<int,int> _position;
    pair<int,int> _prevPos;
    Anthill _anthill;

    //Methods
    bool checkPosition(vector<pair<int,int>> forbiddenPositions, int posX, int posY);
    pair<int,int> getRandomPos(vector<pair<int, int>> forbiddenPositions, int prevX, int prevY, int posX, int posY);
    bool isNextTo(int antX, int antY, int objX, int objY);

};

#endif // WARRIOR_H
