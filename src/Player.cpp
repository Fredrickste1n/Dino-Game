#include <iostream>
#include <raylib.h>
#include "Player.h"

using namespace std;



    void Player::Draw() {
        DrawRectangle(x, y, width, height, PINK);
    };

    void Player::Update() {
    };