#include <vector>

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
public:
    float x;
    float y;
    float width, height;
    int speedX;
    
    void Draw();
    void Update();
};

#endif