#include <iostream>
#include <vector>
#include <algorithm>
#include <raylib.h>
#include "Obstacle.h"
#include "GameRules.h"

using namespace std;

void GetObstacles(std::vector<Obstacle>& obstacles) {
    Obstacle currentObstacle = obstacles.front();

    if(currentObstacle.x < GetScreenWidth() / 2) {
        cout << "drawing new obstacle" << endl;
        Obstacle newObstacle = currentObstacle;
        newObstacle.x = GetScreenWidth();
        obstacles.insert(obstacles.begin(), newObstacle);   // add new obstacle to front of obstacles
    }
}

void DrawObstacles(std::vector<Obstacle> obstacles) {
    for(Obstacle obstacle : obstacles) {
        obstacle.Draw();
    }
}

void UpdateObstacles(std::vector<Obstacle>& obstacles) {
    int vecSize = obstacles.size();
    for(int i = 0; i < vecSize; i++) {
        Obstacle obstacle = obstacles.at(i);
        obstacles.erase(obstacles.begin() + i);
        obstacle.x -= obstacle.speedX;
        obstacles.insert(obstacles.begin() + i, obstacle);
/*
        if(obstacle.x < GetScreenWidth() - obstacle.width) {  
            obstacles.erase(obstacles.begin() + i);
        } */
    }
}