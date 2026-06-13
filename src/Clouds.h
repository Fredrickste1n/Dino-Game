#include <raylib.h>

#ifndef CLOUDS_H
#define CLOUDS_H

class Clouds {
public:
    float x, y;
    Texture2D texture;

    void Draw();
    void Update();
};

#endif