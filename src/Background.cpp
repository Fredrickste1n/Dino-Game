#include <iostream>
#include "Background.h"

void Background::Draw() {
    clouds1.Draw();
    clouds2.Draw();
    ground1.Draw();
    ground2.Draw();
}

void Background::Update() {
    UpdateClouds();
    UpdateGround();
}

void Background::UpdateClouds() {
    clouds1.Update();
    clouds2.Update();

    if(clouds1.x == 0) {
        clouds2.x = GetScreenWidth();
    }

    if(clouds2.x == 0) {
        clouds1.x = GetScreenWidth();
    }
}

void Background::UpdateGround() {
    ground1.Update();
    ground2.Update();

    if(ground1.x <= 0) {
        ground2.x = ground1.x + GetScreenWidth();
    }

    if(ground2.x <= 0) {
        ground1.x = ground2.x + GetScreenWidth();;
    }
}