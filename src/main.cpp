#include <iostream>
#include <raylib.h>
#include <stdio.h>
#include "Player.h"
#include "Floor.h"

using namespace std;

// Constants for screen
const int screenWidth = 1280;
const int screenHeight = 800;

Floor floor;
Player player;

int main() {
    cout << "starting game" << endl;

    InitWindow(screenWidth, screenHeight, "Dino Game"); // Creates window

    SetTargetFPS(60);   // Caps fps

    // Floor Attributes
    floor.width = screenWidth;
    floor.height = 2 * screenHeight / 5;
    floor.x = 0;
    floor.y = 3 * screenHeight / 5;

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
        floor.Update();
        player.Update();

        // Checking for collisions


        // Drawing
        //---------------------------------------------------------------------------------------------------
        ClearBackground(SKYBLUE); // Clears bg every frame
        floor.Draw();
        player.Draw();

        // Print titles
        DrawText(TextFormat("Dino Game"), 0, 0, 40, PURPLE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}