#include <iostream>
#include <raylib.h>
#include "Floor.h"

using namespace std;

void Floor::Draw() {
    DrawRectangle(x, y, width, height, PURPLE);
}

void Floor::Update() {
    
}