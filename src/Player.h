#include "Floor.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    float x, y;
    float width, height;
    bool isAlive;
    float yVelocity;
    float gravAcc;
    Floor floor;

    void Draw();
    void Update();

private:
    bool PlayerCollideFloor();
    int PlayerFloorCollisionY();
    void Fall();
    void Jump();
};

#endif