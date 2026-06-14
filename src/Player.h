#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    float x, y;
    float width, height;
    bool isAlive;

    float yVelocity;
    float gravAcc;
    bool isCollideFloor;

    Texture2D textureFirst, textureSecond, currentTexture;

    void Draw();
    void Update();
    void Animate(int frames);

private:
    void Fall();
    void Jump();
    void PlayerDie();
};

#endif