#ifndef PLAYER_H
#define PLAYER_H


#include "raylib.h"

extern int playerRadius;


class Player {

    private:
        float x, y;
        int speedX = 0, speedY = 0;
        int radius = 30;
        float gravity = 5;
        bool isAirborne = false;

    public:

        Player(float x, float y):
        x(x),
        y(y)
        {}

        void Draw(){
            DrawCircle(x, y, radius, WHITE);
        };

        void Update(){
            limitMovement();
            horizontalMovement();
            playerJump();

            x += speedX;
            y += speedY;
        }

        void limitMovement() {
            if(y - radius <= 0){
                y = radius;
                speedY = 0;
            }

            else if(y + radius >= GetScreenHeight() && !IsKeyDown(KEY_SPACE)){
                y = GetScreenHeight() - radius;
                speedY = 0;
            }

            if(x - radius <= 0){
                x = radius;
                speedX = 0;
            }

            else if(x + radius >= GetScreenWidth()){
                x = GetScreenWidth() - radius;
                speedX = 0;
            }
            
        };

        void horizontalMovement(){
            if(IsKeyDown(KEY_RIGHT)){
                speedX = 5;
            }

            else if(IsKeyDown(KEY_LEFT)){
                speedX = -5;
            }

            else{
                speedX = 0;
            }
        }

        void checkAirborne(){
           if(y + radius <  GetScreenHeight() && speedY == 0) {
            isAirborne = true;
           }
           else{
            isAirborne = false;
           }
        };

        void playerJump(){
        }


        float getX(){return x;};
        float getY(){return y;};
        int getSpeedX(){return speedX;};
        int getSpeedY(){return speedY;}; 
};


#endif