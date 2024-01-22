#include "player.h"
#include <iostream>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

int main(){
    Player player;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Platformer");
    SetTargetFPS(60);
    player.initPlayerTexture();

    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            player.Update();    
            player.Draw();
        EndDrawing();
    }
    CloseWindow();
}
