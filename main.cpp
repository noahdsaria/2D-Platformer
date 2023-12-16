#include "player.h"
#include <iostream>

int main(){
    const int screenWidth = 1200;
    const int screenHeight = 800;
    std::cout << GetScreenHeight() << std::endl;
    Player player(screenWidth / 2, screenHeight / 2, 0, 0, 30);

    InitWindow(screenWidth, screenHeight, "Platformer");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BLACK);
        player.Draw();

        EndDrawing();
    }

    CloseWindow();
}