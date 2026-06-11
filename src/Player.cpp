#include <iostream>
#include <raylib.h>
#include "Player.h"

using namespace std;

void Player::Draw() {
    DrawRectangle(x, y, width, height, PINK);
};

void Player::Update() {
    Fall();
    
};

bool Player::PlayerBelowFloor() {
    if(floor.y > y + height) {
        y = floor.y - height;
        return true;
        cout << "im falling through the floor!";
    }

    return false;
}

void Player::Fall() {
    if(floor.y < y + height && !PlayerBelowFloor()) {
        yVelocity = yVelocity + gravAcc;
        y += yVelocity;
    }
    
}

void Player::Jump() {
    if(floor.y == y + height) {
        
    }
}