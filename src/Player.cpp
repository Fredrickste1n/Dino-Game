#include <iostream>
#include <raylib.h>
#include <cmath>
#include "Player.h"
#include "Floor.h"

using namespace std;

void Player::Draw() {
    DrawRectangle(x, y, width, height, PINK);
};

void Player::Update() {
    Fall();
    Jump();
};

// Checks if player is colliding with floor
// Keeps player above floor
bool Player::PlayerCollideFloor() {
    Rectangle playerRect = {x, y, width, height};
    Rectangle floorRect = {floor.x, floor.y, floor.width, floor.height};
    Rectangle collisionRect = GetCollisionRec(playerRect, floorRect);
    int collisionY = (int)collisionRect.height;

    bool isColliding = CheckCollisionRecs(playerRect, floorRect);

    y -= collisionY;

    return isColliding;
}

void Player::Fall() {
    if(!PlayerCollideFloor()) {
        yVelocity = yVelocity + gravAcc;
        y += yVelocity;
    }
}

void Player::Jump() {
    if(PlayerCollideFloor() && IsKeyPressed(KEY_SPACE)) {
        y--; // prevents player from colliding with floor
        yVelocity = -7;
    }
}