#include <iostream>
#include <raylib.h>
#include "Player.h"

using namespace std;

void Player::Draw() {
    DrawRectangle(x, y, width, height, PINK);
};

void Player::Update() {
    Fall();
    Jump();
};

void Player::Fall() {
    if(!isCollideFloor) {
        yVelocity = yVelocity + gravAcc;
        y += yVelocity;
    }
}

void Player::Jump() {
    if(isCollideFloor && IsKeyPressed(KEY_SPACE)) {
        y--; // prevents player from colliding with floor
        yVelocity = -7;
    }
}