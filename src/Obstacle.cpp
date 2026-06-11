#include <iostream>
#include <raylib.h>
#include "Obstacle.h"

using namespace std;

void Obstacle::Draw() {
    DrawRectangle(x, y, width, height, RED);
}

void Obstacle::Update() {
    x = x - speedX;
}