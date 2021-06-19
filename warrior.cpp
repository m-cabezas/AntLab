#include "warrior.h"

/**
 * @brief default constructor of warrior
 */
Warrior::Warrior() {

}

/**
 * @brief main constructor of warrior
 * @param position
 * @param name
 * @param anthill
 * @param config
 */
Warrior::Warrior(pair<int, int> position, string name, Anthill *anthill, CONFIG &config) {
    _name = name;
    _anthill = anthill;
    _foodCapacity = config.capacityWarrior;
    _currentFood = 0;
    _mode = 0;
    _currentAge = config.ageWarrior;
    _foodCons = config.consWarrior;
    //Init Ant position with the anthill position -1 on X
    _position = position;
    _prevPos = position;
    _mode = 1;
    _maxHealth = config.lifeWarrior;
    _currentHealth = config.lifeWarrior;
}

/**
 * @brief default destructor of warrior
 */
Warrior::~Warrior() {
}

/**
 * @brief method used to access the position of the current warrior
 * @return
 */
const pair<int, int> Warrior::getPosition() {
    return _position;
}

/**
 * @brief method used to access food level of a warrior
 * @return
 */
int Warrior::getCurrentFood() const {
    return _currentFood;
}

/**
 * @brief method used to set the food level of a warrior
 * @param food
 */
void Warrior::setCurrentFood(unsigned int food) {
    _currentFood = food;
}

/**
 * @brief moving method for warrior based on random moves
 * @param forbiddenPositions
 */
void Warrior::explore(vector <pair<int, int>> forbiddenPositions) {
    pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second, _position.first,
                                              _position.second);
    _prevPos.first = _position.first;
    _prevPos.second = _position.second;
    _position.first = newPosition.first;
    _position.second = newPosition.second;
}

/**
 * @brief moving method for warrior based on the idea that the warrior know the path
 * @param forbiddenPositions
 */
void Warrior::returnToAnthill(vector <pair<int, int>> forbiddenPositions) {
    int posX = _position.first;
    int posY = _position.second;
    int anthillX = _anthill->getPosition().first;
    int anthillY = _anthill->getPosition().second;
    //If the Ant is already at the anthill, it gives it food to it
    if (isNextTo(posX, posY, anthillX, anthillY)) {
        giveFood();
        return;
    }
    //If the Ant is on the right X
    if (posX == anthillX - 1) {
        if (posY > anthillY) {
            if (checkPosition(forbiddenPositions, posX, posY - 1)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY - 1;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if (posY < anthillY) {
            if (checkPosition(forbiddenPositions, posX, posY + 1)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY + 1;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }
    } else if (posY == anthillY) {
        // If the Ant is on the right Y
        if (posX > anthillX) {
            if (checkPosition(forbiddenPositions, posX - 1, posY)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX - 1;
                _position.second = posY;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if (posX < anthillX) {
            if (checkPosition(forbiddenPositions, posX + 1, posY)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX + 1;
                _position.second = posY;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }
    } else {
        // If the Ant is not on any axes of the anthill, it tries to get closer starting with the X axe
        if (posX > anthillX) {
            if (checkPosition(forbiddenPositions, posX - 1, posY)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX - 1;
                _position.second = posY;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if (posX < anthillX) {
            if (checkPosition(forbiddenPositions, posX + 1, posY)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX + 1;
                _position.second = posY;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if (posY > anthillY) {
            if (checkPosition(forbiddenPositions, posX, posY - 1)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY - 1;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        } else if (posY < anthillY) {
            if (checkPosition(forbiddenPositions, posX, posY + 1)) {
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = posX;
                _position.second = posY + 1;
            } else {
                pair<int, int> newPosition = getRandomPos(forbiddenPositions, _prevPos.first, _prevPos.second,
                                                          _position.first, _position.second);
                _prevPos.first = posX;
                _prevPos.second = posY;
                _position.first = newPosition.first;
                _position.second = newPosition.second;
            }
        }
    }
}


/**
 * @brief indicates to the ant that she can take the given quantity of food
 * @param availableQuantity quantity of food the ant can take, this does not mean that the ant will take it all
 * @return the actual taken quantity
 */
int Warrior::takeFood(int availableQuantity) {
    if (availableQuantity > 0) {
        //if the ant can take food, it has to go back to the anthill after
        _mode = 2; // We change the ant mode
    }
    if (_currentFood < _foodCapacity) {
        int tmpFood = _currentFood;
        _currentFood += availableQuantity;
        if (_currentFood > _foodCapacity) {
            _currentFood = _foodCapacity;
        }
        return _currentFood - tmpFood;
    }
    return 0;
}

/**
 * @brief interaction method that warriors use to put food in the Anthill
 */
void Warrior::giveFood() {
    _anthill->addFood(_currentFood);
    _currentFood = 0;
    _mode = 1;
}

/**
 * @brief gives a random position considering the previous position of the ant, the current position and the forbidden
 * @param forbiddenPositions
 * @param prevX
 * @param prevY
 * @param posX
 * @param posY
 * @return a proposition of available position
 */
pair<int, int>
Warrior::getRandomPos(vector <pair<int, int>> forbiddenPositions, int prevX, int prevY, int posX, int posY) {
    //List of candidates
    pair<int, int> up;
    up.first = posX;
    up.second = posY - 1;
    pair<int, int> down;
    down.first = posX;
    down.second = posY + 1;
    pair<int, int> left;
    left.first = posX - 1;
    left.second = posY;
    pair<int, int> right;
    right.first = posX + 1;
    right.second = posY;

    vector <pair<int, int>> candidates;
    candidates.push_back(up);
    candidates.push_back(down);
    candidates.push_back(left);
    candidates.push_back(right);

    //Iterating threw the candidates
    vector <pair<int, int>> availableCandidates;
    for (unsigned int i = 0; i < candidates.size(); i++) {
        if (checkPosition(forbiddenPositions, candidates[i].first, candidates[i].second) &&
            (candidates[i].first != prevX || candidates[i].second != prevY)) {
            pair<int, int> available;
            available.first = candidates[i].first;
            available.second = candidates[i].second;
            availableCandidates.push_back(available);
        }
    }

    pair<int, int> result;
    if (availableCandidates.size() > 0) {
        default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
        srand(time(0));
        int random = rand() % availableCandidates.size() + 0;
        result.first = availableCandidates[random].first;
        result.second = availableCandidates[random].second;
    } else if (checkPosition(forbiddenPositions, prevX, prevY)) {
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
 * @brief iterate through the forbidden positions to check if the given X and Y are available
 * @param forbiddenPositions list of impossible move for the ant
 * @param posX the X coordinate you want to check
 * @param posY the Y coordinate you want to check
 * @return true if the position is available, false if not
 */
bool Warrior::checkPosition(vector <pair<int, int>> forbiddenPositions, int posX, int posY) {
    for (unsigned int i = 0; i < forbiddenPositions.size(); i++) {
        if (forbiddenPositions[i].first == posX && forbiddenPositions[i].second == posY) {
            return false;
        }
    }
    return true;
}

/**
 * @brief method used to access the movement mode of the warrior
 *  mode = 1 : Exploration mode, the ant is looking for food
 *  mode = 2 : Return to anthill, the ant is carring food and taking it back to the anthill
 * @return current mode
 */
int Warrior::getMode() const {
    return _mode;
}

/**
 * @brief methods used to tell if your ant is next to an object
 * @param myX
 * @param myY
 * @param objX
 * @param objY
 * @return true
 */
bool Warrior::isNextTo(int antX, int antY, int objX, int objY) {
    if ((objX == antX + 1 && objY == antY) || (objX == antX - 1 && objY == antY) ||
        (objX == antX && objY == antY + 1) || (objX == antX && objY == antY - 1)) {
        return true;
    }
    return false;
}

/**
 * @brief return the position at the round n-1 of the warrior
 * @return return the previous position as pair<int,int>
 */
pair<int, int> const Warrior::getPrevPos() {
    return _prevPos;
}


