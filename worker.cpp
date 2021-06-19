#include "worker.h"

/**
 * @brief default constructor of worker
 */
Worker::Worker() {

}

/**
 * @brief main constructor of worker
 * @param config
 * @param name
 */
Worker::Worker(CONFIG &config, string name) {
    _name = name;
    _currentAge = config.ageWorker;
    _maxHealth = config.lifeWorker;
    _foodCons = config.consWorker;
    _currentHealth = config.lifeWorker;
}

/**
 * @brief default destructor of worker
 */
Worker::~Worker() {
}
