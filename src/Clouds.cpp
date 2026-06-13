#include <iostream>
#include <raylib.h>
#include "Clouds.h"

void Clouds::Draw() {
    DrawTextureV(texture, {x, y}, WHITE);
}

void Clouds::Update() {
    x -= 1;
}