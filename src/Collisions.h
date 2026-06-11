#include "Floor.h"
#include "Player.h"
#include "Obstacle.h"

#ifndef COLLISIONS_H
#define COLLISIONS_H

bool PlayerCollideFloor(Floor floor, Player player);
int PlayerDepthInFloor(Floor floor, Player player);

#endif