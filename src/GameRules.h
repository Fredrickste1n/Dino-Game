#include <vector>
#include "Obstacle.h"

#ifndef GAMERULES_H
#define GAMERULES_H

void GetObstacles(std::vector<Obstacle>& obstacles);
void DrawObstacles(std::vector<Obstacle> obstacles);
void UpdateObstacles(std::vector<Obstacle>& obstacles);

#endif