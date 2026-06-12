#include <iostream>
#include <raylib.h>
#include "Collisions.h"

using namespace std;

bool PlayerCollideFloor(Player player, Floor floor) {
    Rectangle playerRect = {player.x, player.y, player.width, player.height};
    Rectangle floorRect = {floor.x, floor.y, floor.width, floor.height};

    bool isColliding = CheckCollisionRecs(playerRect, floorRect);

    return isColliding;
}

float PlayerDepthInFloor(Player player, Floor floor) {
    Rectangle playerRect = {player.x, player.y, player.width, player.height};
    Rectangle floorRect = {floor.x, floor.y, floor.width, floor.height};
    Rectangle collisionRect = GetCollisionRec(playerRect, floorRect);
    float collisionY = collisionRect.height;

    return collisionY;
}

bool PlayerCollideObstacle(Player player, Obstacle obstacle) {
    Rectangle playerRect = {player.x, player.y, player.width, player.height};
    Rectangle obstacleRect = {obstacle.x, obstacle.y, obstacle.width, obstacle.height};

    bool isColliding = CheckCollisionRecs(playerRect, obstacleRect);

    return isColliding;
}

bool PlayerPassObstacle(Player player, Obstacle obstacle) {
    if(player.x + player.width / 2 >= obstacle.x) {
        return true;
    }
    return false;
}