#include "warrior.h"

Warrior::Warrior()
{

}

Warrior::Warrior(CONFIG &config, string name, Anthill &anthill)
{
    _config = config;
    _name = name;
    _anthill = anthill;
    _foodCapacity = config.capacityWarrior;
    _currentFood = 0;
    _mode = 0;
    //Init Ant position with the anthill position -1 on X
    _position.first = _anthill.getPosition().first-1;
    _position.second = _anthill.getPosition().second;
    _prevPos.first = _anthill.getPosition().first-1;
    _prevPos.second = _anthill.getPosition().second;
}

Warrior::~Warrior()
{

}

const pair<int,int> Warrior::getPosition()
{
    return _position;
}

void Warrior::explore(vector<pair<int,int>> forbiddenPositions)
{
    cout << "Warrior " << _name << " is exploring" << endl;
    pair<int,int> newPosition =  getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
    _position.first = newPosition.first;
    _position.second = newPosition.second;
    cout << "\t=> Warrior is going to : x=" <<  _position.first << " y=" << _position.second << endl;
}

void Warrior::returnToAnthill(vector<pair<int,int>> forbiddenPositions)
{
    cout << "Warrior " << _name << " returns to Anthill" << endl;
    int posX = _position.first;
    int posY = _position.second;
    int anthillX = _anthill.getPosition().first;
    int anthillY = _anthill.getPosition().second;
    //If the Ant is already at the anthill, we do nothing
    if(posX == anthillX-1 && posY == anthillY)
    {
        return ;
    }
    //If the Ant is on the right X
    if(posX == anthillX-1){
        if(posY > anthillY) {
            if(checkPosition(forbiddenPositions, posX,posY-1))
            {
               _prevPos.first = posX;
               _prevPos.second = posY;
               _position.first = posX;
               _position.second = posY-1;
            } else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if(posY < anthillY) {
            if(checkPosition(forbiddenPositions, posX,posY+1)){
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY+1;
            }else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }
    } else if(posY == anthillY){
        // If the Ant is on the right Y
        if(posX > anthillX) {
            if(checkPosition(forbiddenPositions, posX-1,posY))
            {
               _prevPos.first = posX;
               _prevPos.second = posY;
               _position.first = posX-1;
               _position.second = posY;
            } else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if(posX < anthillX) {
            if(checkPosition(forbiddenPositions, posX+1,posY)){
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX+1;
                _position.second = posY;
            }else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }
    } else {
        // If the Ant is not on any axes of the anthill, it tries to get closer starting with the X axe
        if(posX > anthillX) {
            if(checkPosition(forbiddenPositions, posX-1,posY))
            {
               _prevPos.first = posX;
               _prevPos.second = posY;
               _position.first = posX-1;
               _position.second = posY;
            } else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if(posX < anthillX) {
            if(checkPosition(forbiddenPositions, posX+1,posY)){
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX+1;
                _position.second = posY;
            }else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }else if(posY > anthillY) {
            if(checkPosition(forbiddenPositions, posX,posY-1))
            {
               _prevPos.first = posX;
               _prevPos.second = posY;
               _position.first = posX;
               _position.second = posY-1;
            } else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if(posY < anthillY) {
            if(checkPosition(forbiddenPositions, posX,posY+1)){
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY+1;
            }else {
                pair<int,int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }        
    }
    cout << "\t=> Warrior is going to : x=" <<  _position.first << " y=" << _position.second << endl;
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

/**
 * @brief Warrior::getRandomPos Gives a random position considering the previous position of the ant, the current position and the forbidden
 * @param forbiddenPositions
 * @param prevX
 * @param prevY
 * @param posX
 * @param posY
 * @return a proposition of available position
 */
pair<int,int> Warrior::getRandomPos(vector<pair<int, int>> forbiddenPositions, int prevX, int prevY, int posX, int posY)
{
    //List of candidates
    pair<int, int> up;
    up.first = posX;
    up.second = posY-1;
    pair<int, int> down;
    down.first = posX;
    down.second = posY+1;
    pair<int, int>  left;
    left.first = posX-1;
    left.second = posY;
    pair<int, int> right;
    right.first = posX+1;
    right.second = posY;

    vector<pair<int,int>> candidates;
    candidates.push_back(up);
    candidates.push_back(down);
    candidates.push_back(left);
    candidates.push_back(right);

    //Iterating threw the candidates
    vector<pair<int,int>> availableCandidates;
    for(unsigned int i = 0; i < candidates.size(); i++)
    {
        if(checkPosition(forbiddenPositions, candidates[i].first, candidates[i].second) && candidates[i].first != prevX && candidates[i].second != prevY)
        {
            pair<int,int> available;
            available.first = candidates[i].first;
            available.second = candidates[i].second;
            availableCandidates.push_back(available);
        }
    }

    pair<int, int> result;
    if(availableCandidates.size() >  0){
        int random = rand () % availableCandidates.size() + 0;
        result.first = availableCandidates[random].first;
        result.second = availableCandidates[random].second;
    } else if(checkPosition(forbiddenPositions, prevX, prevY)){
        //If there are no more available candidates, the ant tries to go back
        result.first = prevX;
        result.second = prevY;
    } else {
        //If the ant can't go back, it stays at the same position
        result.first = posX;
        result.second = posY;
    }



    return result;
}

/**
 * @brief Warrior::checkPosition Iterate through the forbidden positions to check if the given X and Y are available
 * @param forbiddenPositions list of impossible move for the ant
 * @param posX the X coordinate you want to check
 * @param posY the Y coordinate you want to check
 * @return true if the position is available, false if not
 */
bool Warrior::checkPosition(vector<pair<int, int>> forbiddenPositions, int posX, int posY)
{
    for(unsigned int i= 0 ; i < forbiddenPositions.size(); i++)
    {
        if (forbiddenPositions[i].first == posX && forbiddenPositions[i].second == posY)
        {
            return false;
        }
    }
    return true;
}
