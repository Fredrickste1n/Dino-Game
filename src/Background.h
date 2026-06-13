#include <raylib.h>
#include "Clouds.h"
#include "Ground.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background {
public:
    float x, y;
    Clouds clouds1, clouds2;
    Ground ground1, ground2;

    void Draw();
    void Update();
    void UpdateClouds();
    void UpdateGround();
};

#endif