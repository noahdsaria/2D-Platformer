#ifndef PLAYER_H
#define PLAYER_H


#include "raylib.h"

extern int playerRadius;


class Player {
    private:
        float x, y;
        int speedX, speedY;
        int radius;

    public:

        Player(float x, float y, int speedX, int speedY, int radius):
        x(x),
        y(y),
        speedX(speedX),
        speedY(speedY), 
        radius(radius)
        {}

        void Draw(){
            DrawCircle(x, y, radius, WHITE);
        };

        void Update(){
            x += speedX;
            y += speedY;

            checkCollision();
        }

        void checkCollision(){
            if(y + radius >= GetScreenHeight()){
                speedY *= 0;
            }
        }

        float getX(){return x;};
        float getY(){return y;};
        int getSpeedX(){return speedX;};
        int getSpeedY(){return speedY;}; 
};


#endif