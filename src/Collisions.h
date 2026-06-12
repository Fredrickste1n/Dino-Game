#include "Floor.h"
#include "Player.h"
#include "Obstacle.h"

#ifndef COLLISIONS_H
#define COLLISIONS_H

// Player and floor
bool PlayerCollideFloor(Player player, Floor floor);
float PlayerDepthInFloor(Player player, Floor floor);

// Player and Obstacles
bool PlayerCollideObstacle(Player player, Obstacle obstacle);

#endif