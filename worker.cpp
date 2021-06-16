#include "worker.h"

/***
 * @brief default constructor of worker
 */
Worker::Worker()
{

}

/***
 * @brief main constructor of worker
 * @param config
 * @param name
 */
Worker::Worker(CONFIG &config, string name) {
    _name = name;
//    cout << "Init Worker '" << name << "' with age : " << CONFIG["ageWorker"] << endl;
    _currentAge = config.ageWorker;
    _maxHealth = config.lifeWorker;
    _foodCons = config.consWorker;
    _currentHealth = config.lifeWorker;
}

/***
 * @brief default destructor of worker
 */
Worker::~Worker()
{
    //cout << "Oh no ! Worker " << _name << " died unexpectidely ! :-(" << endl;
}
