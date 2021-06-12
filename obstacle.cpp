#include "obstacle.h"

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(pair <int,int> position, int width, int height)
{
    _position = position;
    _width = width;
    _height = height;
}

Obstacle::~Obstacle()
{

}

const pair<int,int> Obstacle::getPosition(){
    return _position;
}
