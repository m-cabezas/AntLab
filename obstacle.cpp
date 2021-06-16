#include "obstacle.h"

/***
 * @brief default constructor of obstacle
 */
Obstacle::Obstacle()
{

}

/***
 * @brief main constructor of obstacle
 * @param position
 * @param width
 * @param height
 */
Obstacle::Obstacle(pair <int,int> position, int width, int height)
{
    _position = position;
    _width = width;
    _height = height;
}

/***
 * @brief default destructor of obstacle
 */
Obstacle::~Obstacle()
{

}

/***
 * @brief method used to access the coordinates of the obstacle
 * @return
 */
const pair<int,int> Obstacle::getPosition(){
    return _position;
}
