#include <iostream>
#include <vector>
#include <raylib.h>
#include "Obstacle.h"

using namespace std;

void Obstacle::Draw() {
    //DrawRectangle(x, y, width, height, RED);
    DrawTextureV(texture, (Vector2) {x, y}, WHITE);
}

void Obstacle::Update() {
    x = x - speedX;
}