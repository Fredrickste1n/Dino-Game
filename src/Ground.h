#include <raylib.h>

#ifndef GROUND_H
#define GROUND_H

class Ground {
public:
    float x, y;
    Texture2D texture;

    void Draw();
    void Update();
};

#endif