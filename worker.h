#ifndef WORKER_H
#define WORKER_H

#include "larva.h"
#include "util.h"

class Worker : public Larva {
public:
    //Methods
    Worker();

    Worker(CONFIG &config, string name);

    ~Worker();
};

#endif // WORKER_H
