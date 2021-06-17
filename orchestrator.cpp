#include "orchestrator.h"

/***
 * @brief default constructor of orchestrator
 */
Orchestrator::Orchestrator() {

}

/***
 * @brief main constructor of orchestrator
 * @param config
 */
Orchestrator::Orchestrator(CONFIG config) {
    _config = config;
    _dimension = pair<int, int>(100, 50);
    // Initializing the grid
    _grid.resize(_dimension.first);
    _obstaclesGrid.resize(_dimension.first);
    _foodSpawnersGrid.resize(_dimension.first);
    _anthillsGrid.resize(_dimension.first);
    for (unsigned int i = 0; i < _grid.size(); i++) {
        _grid.at(i).resize(_dimension.second);
        _obstaclesGrid.at(i).resize(_dimension.second);
        _foodSpawnersGrid.at(i).resize(_dimension.second);
        _anthillsGrid.at(i).resize(_dimension.second);
    }
    // Initializing grid at false
    for (int x = 0; x < _dimension.first; x++) {
        for (int y = 0; y < _dimension.second; y++) {
            _grid.at(x).at(y) = false;
            _obstaclesGrid.at(x).at(y) = false;
            _foodSpawnersGrid.at(x).at(y) = false;
            _anthillsGrid.at(x).at(y) = false;
        }
    }
}

/**
 * @brief default destructor of orchestrator
 */
Orchestrator::~Orchestrator() {

}

/***
 * @brief method used to access the dimensions of the orchestrator map
 * @return
 */
pair<int, int> Orchestrator::getDimension() const {
    return _dimension;
}

/**
 * @brief return an int mapped to an object moving on the map
 * @param x
 * @param y
 * @return 1 if there is nothing, 2 if there is an obstacle, 3 if there is a foodSpawner, 4 if it is the anthill  and 5 for a warrior
 */
int Orchestrator::getMapEntity(int x, int y) {
    if (_grid.at(x).at(y) == false) {
        return 1; // There is nothing
    }
    if (_foodSpawnersGrid.at(x).at(y) == true) {
        return 3; // It is a FoodSpawner
    }
    if (_anthillsGrid.at(x).at(y) == true) {
        return 4; // It is the anthill
    }
    if (_obstaclesGrid.at(x).at(y) == true) {
        return 2; // It is an obstacle
    }
    //return code for warriors : 5
    return 5;
}

/**
 * @brief initialize entities on the map at first round
 * @param config
 */
void Orchestrator::initOrch(CONFIG config) {
    cout << "\t- Init Orchestrator : Environment of size x=" << _dimension.first << " y=" << _dimension.second << endl;
    _config = config;
    pair<int, int> anthillPosition(_dimension.first / 2, _dimension.second / 2);
    createAnthill(anthillPosition, true);
    initFoodSpawners(_config.nbFoodSpawnerInit);
    initObstacles(_config.nbObstacleInit);
    initWarriors(_config.nbWarriorInit, _anthills[0]);
}

/**
 * @brief Orchestrator::doRound the orchestrator do the round of the anthill and warriors
 * @return 0 if everything is fine, 1 if the queen is dead
 */
int Orchestrator::doRound() {
    // Anthill
    _anthills[0]->doRound();
    int numberNewWarriors = _anthills[0]->getNewWarriors();
    // If the population is under the max population, we give the option to the anthill to make new eggs
    if (_anthills[0]->getPopulation() + _warriors.size() < _config.maxPopAnthill) {
        _anthills[0]->spawnEgg();
    }


    //Iterating through the foodSpawners
    for (unsigned int i = 0; i < _foodSpawners.size(); i++) {
        _foodSpawners[i]->doRound();
    }

    //Warriors
    //creating the new warriors (workers that grown up)
    initWarriors(numberNewWarriors, _anthills[0]);
    vector < Warrior * > newWarriors;
    // Iterating through the warriors
    for (unsigned int i = 0; i < _warriors.size(); i++) {
        pair<int, int> warriorPos = _warriors[i]->getPosition();
        // Managing warrior's life
        _warriors[i]->increaseAge();
        _warriors[i]->starve();
        // If the ant is not dead, we add it to the new ant list
        if (_warriors[i]->getCurrentHealth() <= 0) {
            delete _warriors[i];
            setCaseTaken(warriorPos.first, warriorPos.second, false);
            continue;
        }
        // If the ant is at half is life, we give food to it if possible
        if (_warriors[i]->getCurrentHealth() <= (_config.lifeLarva / 2)) {
            if (_warriors[i]->getCurrentFood() > 0) {
                int heal = rand() % _warriors[i]->getCurrentFood() + 0;
                _warriors[i]->heal(heal);
                _warriors[i]->setCurrentFood(_warriors[i]->getCurrentFood() - heal);
            }
        }

        // Managing warrior's moves
        int mode = _warriors[i]->getMode();
        if (mode == 1) {
            // If the ant is in exploration mode
            FoodSpawner *foodSpawner = checkFoodNearby(warriorPos.first, warriorPos.second);
            if (foodSpawner != NULL) {
                int takenQuantity = _warriors[i]->takeFood(foodSpawner->getCurrentQuantity());
                foodSpawner->decreaseQuantity(takenQuantity);
            } else {
                _warriors[i]->explore(getForbiddenPositions(warriorPos.first, warriorPos.second));
            }
        } else if (mode == 2) {
            _warriors[i]->returnToAnthill(getForbiddenPositions(warriorPos.first, warriorPos.second));
        }
        // Updating the grid with the new position
        pair<int, int> prevPos = _warriors[i]->getPrevPos();
        setCaseTaken(prevPos.first, prevPos.second, false);
        warriorPos = _warriors[i]->getPosition();
        setCaseTaken(warriorPos.first, warriorPos.second, true);
        newWarriors.push_back(_warriors[i]);
    }
    _warriors.clear();
    _warriors = newWarriors;
    cout << "Warrior number: " << _warriors.size() << endl;
    //Checking if the queen is alive, if not, it is the end of the game!
    if (!_anthills[0]->isQueenAlive()) {
        return 1;
    } else {
        return 0;
    }

}

/**
 * @brief create an anthil and add it to the orchestrator's anthill list
 * @param position
 * @param init boolean that indicates if the new anthill need to be initialized with eggs, larvas and workers
 */
void Orchestrator::createAnthill(pair<int, int> position, bool init) {
    cout << "\t\t* Creating Anthill at : x=" << position.first << " y=" << position.second << endl;
    Anthill *anthill = new Anthill(_config, _config.maxPopAnthill, _config.maxFoodAnthill, position, 1, 1);
    if (init) {
        anthill->initAnthill();
    }
    _anthills.push_back(anthill);
    setCaseTaken(position.first, position.second, true);
    _anthillsGrid.at(position.first).at(position.second) = true;
}

/**
 * @brief create a food spawner and add it to the orchestrator's food spawner list
 * @param position
 */
void Orchestrator::createFoodSpawner(pair<int, int> position) {
    cout << "\t\t* Creating FoodSpawner at : x=" << position.first << " y=" << position.second << endl;
    FoodSpawner *foodSpawner = new FoodSpawner(_config.maxFoodFoodSpawner, position, 1, 1);
    _foodSpawners.push_back(foodSpawner);
    setCaseTaken(position.first, position.second, true);
    _foodSpawnersGrid.at(position.first).at(position.second) = true;
}

/**
 * @brief create multiple food spawners at initialization round
 * @param nbFoodSpawnerInit
 */
void Orchestrator::initFoodSpawners(int nbFoodSpawnerInit) {
    default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    cout << "\t\t* Creating FoodSpawners" << endl;
    for (int i = 0; i < nbFoodSpawnerInit; i++) {
        int born = getFreePositions().size();
        uniform_int_distribution<int> distrib{0, born};
        pair<int, int> foodSpawnerPosition = getFreePositions().at(distrib(re));
        createFoodSpawner(foodSpawnerPosition);
    }
}

/**
 * @brief create an obstacle and add it to the orchestrator's obstacle list
 * @param position
 */
void Orchestrator::createObstacle(pair<int, int> position) {
    cout << "\t\t* Creating Obstacle at : x=" << position.first << " y=" << position.second << endl;
    Obstacle *obstacle = new Obstacle(position, 1, 1);
    _obstacles.push_back(obstacle);
    setCaseTaken(position.first, position.second, true);
    _obstaclesGrid.at(position.first).at(position.second) = true;
}

/**
 * @brief create multiple food spawners at initialization round
 * @param nbObstacleInit
 */
void Orchestrator::initObstacles(int nbObstacleInit) {
    cout << "\t\t* Creating obstacles" << endl;
    default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    for (int i = 0; i < nbObstacleInit; i++) {
        int born = getFreePositions().size();
        uniform_int_distribution<int> distrib{0, born};
        pair<int, int> obstaclePosition = getFreePositions().at(distrib(re));
        createObstacle(obstaclePosition);
    }
}

/**
 * @brief create multiple warriors at initialization round
 * @param nbWarriorInit
 * @param anthill
 */
void Orchestrator::initWarriors(int nbWarriorInit, Anthill *anthill) {

    for (int i = 0; i < nbWarriorInit; i++) {
        vector <pair<int, int>> warriorsFreePositions = getWarriorsFreePositions(*anthill);
        if (!warriorsFreePositions.empty()) {
            pair<int, int> warriorPosition = warriorsFreePositions.at(rand() % warriorsFreePositions.size() + 0);
            createWarrior(warriorPosition, anthill);
        } else {
            cout << "\t\t* Unable to create warrior, no more positions available" << endl;
        }
    }
}

/**
 * @brief create a warrior and add it to the orchestrator's warrior list
 * @param position
 * @param anthill
 */
void Orchestrator::createWarrior(pair<int, int> position, Anthill *anthill) {
    string name = "warrior" + to_string(_warriors.size());
    Warrior *warrior = new Warrior(position, name, anthill, _config);
    _warriors.push_back(warrior);
    setCaseTaken(position.first, position.second, true);
}

/**
 * @brief return all empty positions on the map
 * @return return all empty positions on the map as vector<pair <int, int>>
 */
vector <pair<int, int>> Orchestrator::getFreePositions() {
    vector <pair<int, int>> freePositions;

    for (int x = 0; x < _dimension.first; x++) {
        for (int y = 0; y < _dimension.second; y++) {
            if (isCaseTaken(x, y) == false) {
                pair<int, int> freePosition(x, y);
                freePositions.push_back(freePosition);
            }
        }
    }

    return freePositions;
}

/**
 * @brief Orchestrator::getForbidenPositions indicates position where you cannot go next to the coordinates you give
 * @param x
 * @param y
 * @return the occupied position around the given coordinates
 */
vector <pair<int, int>> Orchestrator::getForbiddenPositions(int x, int y) {
    vector <pair<int, int>> forbiddenPositions;
    if (isCaseTaken(x - 1, y)) {
        pair<int, int> forbidden(x - 1, y);
        forbiddenPositions.push_back(forbidden);
    }
    if (isCaseTaken(x + 1, y)) {
        pair<int, int> forbidden(x + 1, y);
        forbiddenPositions.push_back(forbidden);
    }
    if (isCaseTaken(x, y - 1)) {
        pair<int, int> forbidden(x, y - 1);
        forbiddenPositions.push_back(forbidden);
    }
    if (isCaseTaken(x, y + 1)) {
        pair<int, int> forbidden(x, y + 1);
        forbiddenPositions.push_back(forbidden);
    }
    return forbiddenPositions;
}

/**
 * @brief methods used to verify if there is food near the position
 * @param x
 * @param y
 * @return the foodspawner if there is one next to the position, 0 if not
 */
FoodSpawner *Orchestrator::checkFoodNearby(int x, int y) {
    for (unsigned int i = 0; i < _foodSpawners.size(); i++) {
        pair<int, int> foodPos = _foodSpawners[i]->getPosition();
        if (isNextTo(x, y, foodPos.first, foodPos.second)) {
            return _foodSpawners[i];
        }
    }
    return NULL;
}

/**
 * @brief tells if the given position is available
 * @param x
 * @param y
 * @return true if the position is taken, false is it's available
 */
bool Orchestrator::isCaseTaken(int x, int y) {
    if ((x < _dimension.first && x >= 0) && (y < _dimension.second && y >= 0)) {
        return _grid.at(x).at(y);
    } else {
        return true;
    }

}

/**
 * @brief set the location on the map to "taken"
 * @param x
 * @param y
 * @param taken : boolean value of the taken location on the map
 */
void Orchestrator::setCaseTaken(int x, int y, bool taken) {
    if ((x < _dimension.first && x >= 0) && (y < _dimension.second && y >= 0)) {
        _grid.at(x).at(y) = taken;
    }
}

/**
 * @brief tell if your ant is next to an object
 * @param myX
 * @param myY
 * @param objX
 * @param objY
 * @return true
 */
bool Orchestrator::isNextTo(int antX, int antY, int objX, int objY) {
    if ((objX == antX + 1 && objY == antY) || (objX == antX - 1 && objY == antY) ||
        (objX == antX && objY == antY + 1) || (objX == antX && objY == antY - 1)) {
        return true;
    }
    return false;
}

/**
 * @brief get all warriors available position to spawn around the anthill
 * @param anthill
 * @return all warriors free positions as vector<pair <int,int>>
 */
vector <pair<int, int>> Orchestrator::getWarriorsFreePositions(Anthill &anthill) {
    vector <pair<int, int>> warriorsFreePositions;
    vector <pair<int, int>> freePositions = getFreePositions();
    pair<int, int> anthillPosition = anthill.getPosition();
    vector <pair<int, int>> nearbyPositions{pair<int, int>(anthillPosition.first - 1, anthillPosition.second),
                                            pair<int, int>(anthillPosition.first - 1, anthillPosition.second - 1),
                                            pair<int, int>(anthillPosition.first - 1, anthillPosition.second + 1),
                                            pair<int, int>(anthillPosition.first + 1, anthillPosition.second),
                                            pair<int, int>(anthillPosition.first + 1, anthillPosition.second - 1),
                                            pair<int, int>(anthillPosition.first + 1, anthillPosition.second + 1),
                                            pair<int, int>(anthillPosition.first, anthillPosition.second - 1),
                                            pair<int, int>(anthillPosition.first, anthillPosition.second + 1)};
    for (int x = 0; x < int(freePositions.size()); x++) {
        pair<int, int> freePosition = freePositions.at(x);
        for (int y = 0; y < int(nearbyPositions.size()); y++) {
            pair<int, int> nearbyPosition = nearbyPositions.at(y);
            if (freePosition == nearbyPosition) {
                warriorsFreePositions.push_back(freePosition);
            }
        }
    }
    return warriorsFreePositions;
}
