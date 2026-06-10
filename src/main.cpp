#include <iostream>
#include <raylib.h>
#include <stdio.h>
#include "Player.h"

using namespace std;

// Constants for screen
const int screenWidth = 1280;
const int screenHeight = 800;

Player player;

int main() {
    cout << "starting game" << endl;

    InitWindow(screenWidth, screenHeight, "Dino Game"); // Creates window

    SetTargetFPS(60);   // Caps fps

    // Dino Attributes
    player.width = 60;
    player.height = 90;
    player.x = screenWidth / 2 - player.width / 2;
    player.y = screenHeight / 2 - player.height / 2;
    player.isAlive = true;

    // Main game loop
    //-------------------------------------------------------------------------------------------------------
    while(!WindowShouldClose()) {       // Window will close on either X press or esc
        BeginDrawing();

        // Updating
        //---------------------------------------------------------------------------------------------------
        player.Update();

        // Checking for collisions


        // Drawing
        //---------------------------------------------------------------------------------------------------
        ClearBackground(SKYBLUE); // Clears bg every frame
        player.Draw();

        // Print titles
        DrawText(TextFormat("Dino Game"), 0, 0, 40, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}