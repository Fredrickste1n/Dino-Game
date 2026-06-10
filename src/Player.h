#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    float x, y;
    float width, height;
    bool isAlive;

    void Draw();
    void Update();
};

#endif