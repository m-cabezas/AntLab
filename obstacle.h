#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <utility>

using namespace std;

class Obstacle
{
public:
    //Methods
    Obstacle();
    Obstacle(pair <int,int> position, int width, int height);
    ~Obstacle();

    virtual const pair<int,int> getPosition();

protected:
    //Attributes
    pair <int,int> position;
    int width;
    int height;
};

#endif // OBSTACLE_H
