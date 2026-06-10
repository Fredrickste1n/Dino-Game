#include <iostream>
#include <raylib.h>
#include "Player.h"
#include "Floor.h"

using namespace std;



    void Player::Draw() {
        DrawRectangle(x, y, width, height, PINK);
    };

    void Player::Update() {

    };