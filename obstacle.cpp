#include "obstacle.h"

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(pair <int,int> position, int width, int height)
{
    this->position = position;
    this->width = width;
    this->height = height;
}

Obstacle::~Obstacle()
{

}

pair<int,int> Obstacle::getPosition(){
    return position;
}
