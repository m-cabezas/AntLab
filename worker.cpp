#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(CONFIG &config, string name) {
    _name = name;
//    cout << "Init Worker '" << name << "' with age : " << CONFIG["ageWorker"] << endl;
    _currentAge = config.ageWorker;
    _maxHealth = config.lifeWorker;
    _foodCons = config.consWorker;
}

Worker::~Worker()
{

}
