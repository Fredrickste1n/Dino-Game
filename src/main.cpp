#include <iostream>
#include <vector>
#include <raylib.h>
#include <stdio.h>
#include "GameRules.h"
#include "Collisions.h"
#include "Floor.h"
#include "Player.h"
#include "Obstacle.h"

using namespace std;

// Constants for screen
const int screenWidth = 1280;
const int screenHeight = 800;

int playerScore = 0;

Floor floor;
Player player;
Obstacle start;
vector<Obstacle> obstacles;

int main() {
    cout << "starting game" << endl;

    InitWindow(screenWidth, screenHeight, "Dino Game"); // Creates window

    SetTargetFPS(60);   // Caps fps

    // Floor Attributes
    floor.width = screenWidth;
    floor.height = 2 * screenHeight / 5;
    floor.x = 0;
    floor.y = 3 * screenHeight / 5;

    // Player Attributes
    player.width = 64;
    player.height = 96;
    player.x = screenWidth / 2 - player.width / 2;
    player.y = floor.y - player.height;
    player.isAlive = true;
    player.gravAcc = 1.5;
    player.yVelocity = 0;
    player.isCollideFloor = PlayerCollideFloor(player, floor);
    player.texture = LoadTexture("txtrs/dino.png");

    // Start Obstacle Attributes
    start.width = 56;
    start.height = 80;
    start.x = screenWidth + 400;
    start.y = floor.y - start.height;
    start.speedX = 8;
    start.texture = LoadTexture("txtrs/cactus.png");

    obstacles.push_back(start);

    // Main game loop
    //-------------------------------------------------------------------------------------------------------
    while(!WindowShouldClose()) {       // Window will close on either X press or esc
        BeginDrawing();

        // Updating
        //---------------------------------------------------------------------------------------------------
        if(player.isAlive) {
            playerScore = KeepScore(player, obstacles);
            GetObstacles(obstacles);
            UpdateObstacles(obstacles);
            floor.Update();
            player.Update();
        }
        else {
            DrawText(TextFormat("YOU DIED"), screenWidth / 2 - 50, 100, 40, RED);
        }

        // Checking for collisions
        if(player.isAlive) {
            player.isCollideFloor = PlayerCollideFloor(player, floor);
            player.y -= PlayerDepthInFloor(player, floor) - 1;
            for(Obstacle obstacle : obstacles) {
                if(PlayerCollideObstacle(player, obstacle)) {
                    player.isAlive = false;
                }
            }
        }

        // Drawing
        //---------------------------------------------------------------------------------------------------
        ClearBackground(SKYBLUE); // Clears bg every frame
        DrawObstacles(obstacles);
        floor.Draw();
        player.Draw();

        // Print titles
        //---------------------------------------------------------------------------------------------------
        DrawText(TextFormat("Dino Game"), 0, 0, 40, PURPLE);
        DrawText(TextFormat("%i", playerScore), screenWidth / 2 - 40, 20, 40, WHITE);

        if(!player.isAlive && IsKeyPressed(KEY_ENTER)) {
            player.isAlive = true;
            obstacles.clear();
            obstacles.push_back(start);
        }

        EndDrawing();
    }

    UnloadTexture(player.texture);

    CloseWindow();
    return 0;
}