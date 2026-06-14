#include <iostream>
#include <vector>
#include <raylib.h>
#include <stdio.h>
#include "GameRules.h"
#include "Collisions.h"
#include "Floor.h"
#include "Player.h"
#include "Obstacle.h"
#include "Background.h"

using namespace std;

// Constants for screen
const int screenWidth = 1280;
const int screenHeight = 800;

int playerScore = 0;
int frames = 0;

Background bg;
Clouds clouds1;
Clouds clouds2;
Ground ground1;
Ground ground2;
Floor floor;
Player player;
Obstacle start;
vector<Obstacle> obstacles;

int main() {
    cout << "starting game" << endl;

    InitWindow(screenWidth, screenHeight, "Dino Game"); // Creates window

    SetTargetFPS(60);   // Caps fps

    // BackGround Attributes
    //----------------------------------------------------------------------------------
    bg.x = 0;
    bg.y = 0;

    // CLOUDS
    //----------------------------------------------------------------------------------

    bg.clouds1 = clouds1;
    bg.clouds1.x = bg.x;
    bg.clouds1.y = bg.y;
    bg.clouds1.texture = LoadTexture("txtrs/clouds.png");

    bg.clouds2 = clouds2;
    bg.clouds2.x = bg.x + screenWidth;
    bg.clouds2.y = bg.y;
    bg.clouds2.texture = LoadTexture("txtrs/clouds.png");

    // GROUND
    //----------------------------------------------------------------------------------

    bg.ground1 = ground1;
    bg.ground1.x = bg.x;
    bg.ground1.y = bg.y - 8;
    bg.ground1.texture = LoadTexture("txtrs/ground.png");

    bg.ground2 = ground2;
    bg.ground2.x = bg.x + screenWidth;
    bg.ground2.y = bg.y - 8;
    bg.ground2.texture = LoadTexture("txtrs/ground.png");

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
    player.textureFirst = LoadTexture("txtrs/dino.png");
    player.textureSecond = LoadTexture("txtrs/dinoRun.png");

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
            frames++;
            bg.Update();
            playerScore = KeepScore(player, obstacles);
            GetObstacles(obstacles);
            UpdateObstacles(obstacles);
            floor.Update();
            player.Update();
            player.Animate(frames);
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
        bg.Draw();
        DrawObstacles(obstacles);
        player.Draw();

        // Print titles
        //---------------------------------------------------------------------------------------------------
        DrawText(TextFormat("Dino Game"), 0, 0, 40, PURPLE);
        DrawText(TextFormat("%i", playerScore), screenWidth / 2 - 40, 20, 40, BLUE);
        if(!player.isAlive) {
            DrawText(TextFormat("YOU DIED"), screenWidth / 2 - 50, 100, 40, RED);
        }

        if(!player.isAlive && IsKeyPressed(KEY_ENTER)) {
            player.isAlive = true;
            obstacles.clear();
            obstacles.push_back(start);
        }

        EndDrawing();
    }

    UnloadTexture(player.textureFirst);
    UnloadTexture(player.textureSecond);
    UnloadTexture(bg.clouds1.texture);
    UnloadTexture(bg.clouds2.texture);
    UnloadTexture(bg.ground1.texture);
    UnloadTexture(bg.ground2.texture);

    CloseWindow();
    return 0;
}