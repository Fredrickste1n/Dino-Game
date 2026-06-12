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
    PlayerDie();
};

void Player::Fall() {
    if(!isCollideFloor) {
        yVelocity = yVelocity + gravAcc;
        y += yVelocity;
    }
}

void Player::Jump() {
    if(isCollideFloor && IsKeyDown(KEY_SPACE)) {
        y--; // prevents player from colliding with floor so jump is possible
        yVelocity = -25;
    }
}

void Player::PlayerDie() {
    if(!isAlive) {
        if(IsKeyPressed(KEY_SPACE)) {
            isAlive = true;
        }
    }
}