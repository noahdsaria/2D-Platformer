#pragma once
#include "raylib.h"

extern const float GRAVITY;

struct playerTexture{
    Texture2D playerSprite; 
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
};

class Player {

    private:
        float speedX, speedY;
        playerTexture texture;
        bool playerDirection; //0 (default)->right, 1->left
        bool playerMoving;
        int frameCount;
        int playerFrame;
        bool Airborne;
        
    public:

        Player();

        void Update();
        
        void initPlayerTexture();

        void Draw();

        void checkCollision();

        void updatePos();

        void horizontalMove();

        void animateWalk();

        void checkAirborne();

        void verticalMove();
};
