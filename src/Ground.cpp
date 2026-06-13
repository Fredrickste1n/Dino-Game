#include <iostream>
#include <raylib.h>
#include "Ground.h"

void Ground::Draw() {
    DrawTextureV(texture, {x, y}, WHITE);
}

void Ground::Update() {
    x -= 8;
}