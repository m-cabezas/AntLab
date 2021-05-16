#include "warrior.h"

Warrior::Warrior()
{

}

Warrior::Warrior(CONFIG &config, Environment &environment, Anthill &anthill)
{
    _config = config;
    _anthill = anthill;
    _foodCapacity = config.capacityWarrior;
    _currentFood = 0;
    _mode = 0;
    //Init Ant position with the anthill position -1 on X
    _position.first = _anthill.getPosition().first-1;
    _position.second = _anthill.getPosition().second;
    _prevPos.first = _anthill.getPosition().first-1;
    _prevPos.second = _anthill.getPosition().second;
    _environment = environment;
}

Warrior::~Warrior()
{

}

void Warrior::explore()
{

}

void Warrior::returnToAnthill()
{
    cout << "Warrior " << _name << " returns to Anthill" << endl;
    int posX = _position.first;
    int posY = _position.second;
    int anthillX = _anthill.getPosition().first;
    int anthillY = _anthill.getPosition().second;
    //If the Ant is already at the anthill, we do nothing
    if(posX == anthillX-1 && posY == anthillY)
    {
        return;
    }
    //If the Ant is on the right X
    if(posX == anthillX-1){
        if(posY > anthillY) {
            if(_environment.checkPosition(posX,posY-1)
            {
               _prevPos.first = posX;
               _prevPos.second = posY;
               _position.first = posX;
               _position.second = posY-1;
            } else {
                //@TODO
            }
        } else if(posY < anthillY) {
            if(_environment.checkPosition(posX,posY+1)){
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY+1;
            }else {
                //@TODO
            }
        }
    } else if(posY == anthillY){
        // If the Ant is on the right Y
        if(posX > anthillX) {
            if(_environment.checkPosition(posX-1,posY)
            {
               _prevPos.first = posX;
               _prevPos.second = posY;
               _position.first = posX-1;
               _position.second = posY;
            } else {
                //@TODO
            }
        } else if(posX < anthillX) {
            if(_environment.checkPosition(posX+1,posY)){
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX+1;
                _position.second = posY;
            }else {
                //@TODO
            }
        }
    } else {
               //@TODO
    }
}


void Warrior::takeFood()
{

}

void Warrior::attack()
{

}

void Warrior::giveFood()
{

}
