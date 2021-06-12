#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <utility>

using namespace std;

class Obstacle
{
public:
    Obstacle();
    Obstacle(pair <int,int> position, int width, int height);
    ~Obstacle();
    //Methods
    virtual const pair<int,int> getPosition();

protected:
    //Attributs
    pair <int,int> _position;
    int _width;
    int _height;
};

#endif // OBSTACLE_H
