#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(CONFIG config, string name) {
    _name = name;
//    cout << "Init Worker '" << name << "' with age : " << CONFIG["ageWorker"] << endl;
//    _currentAge = CONFIG["ageWorker"];
//    _maxHealth = CONFIG["lifeWorker"];
//    _foodCons = CONFIG["consWorker"];
}

Worker::~Worker()
{

}
