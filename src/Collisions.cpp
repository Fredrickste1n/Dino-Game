#include <iostream>
#include <raylib.h>
#include "Collisions.h"

using namespace std;

// Checks if player is colliding with floor
// Keeps player above floor
bool PlayerCollideFloor(Floor floor, Player player) {
    Rectangle playerRect = {player.x, player.y, player.width, player.height};
    Rectangle floorRect = {floor.x, floor.y, floor.width, floor.height};
    Rectangle collisionRect = GetCollisionRec(playerRect, floorRect);
    int collisionY = (int)collisionRect.height;

    bool isColliding = CheckCollisionRecs(playerRect, floorRect);

    //player.y -= collisionY;

    return isColliding;
}

int PlayerDepthInFloor(Floor floor, Player player) {
    Rectangle playerRect = {player.x, player.y, player.width, player.height};
    Rectangle floorRect = {floor.x, floor.y, floor.width, floor.height};
    Rectangle collisionRect = GetCollisionRec(playerRect, floorRect);
    int collisionY = (int)collisionRect.height;

    return collisionY;
}