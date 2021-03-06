#ifndef WARRIOR_H
#define WARRIOR_H

#include <random>
#include <chrono>

#include "worker.h"
#include "anthill.h"

class Warrior : public Worker {
public:
    //Methods
    Warrior();

    Warrior(pair<int, int> position, string name, Anthill *anthill, CONFIG &config);

    ~Warrior();

    const pair<int, int> getPosition();

    const pair<int, int> getPrevPos();

    void explore(vector <pair<int, int>> forbiddenPositions);

    void returnToAnthill(vector <pair<int, int>> forbiddenPositions);

    int takeFood(int availableQuantity);

    void giveFood();

    int getMode() const;

    int getCurrentFood() const;

    void setCurrentFood(unsigned int food);

private:
    //Attributes
    int _foodCapacity; // the maximum food the ant can carry
    int _currentFood; // The food the ant is carrying
    int _mode;
    pair<int, int> _position;
    pair<int, int> _prevPos;
    Anthill *_anthill;

    //Methods
    bool checkPosition(vector <pair<int, int>> forbiddenPositions, int posX, int posY);

    pair<int, int> getRandomPos(vector <pair<int, int>> forbiddenPositions, int prevX, int prevY, int posX, int posY);

    bool isNextTo(int antX, int antY, int objX, int objY);

};

#endif // WARRIOR_H
