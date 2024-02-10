#include "player.h"
#include <math.h>
#include <iostream>

const float GRAVITY = 60;
// Constructor
Player::Player() : 
speedX(0),
speedY(GRAVITY),
playerDirection(0),
playerMoving(false),
frameCount(0),
playerFrame(1),
Airborne(false)
{};

void Player::Update(){
    horizontalMove();
    verticalMove();
    updatePos();
    checkCollision();
    animateWalk();
};

void Player::initPlayerTexture(){
    texture.playerSprite = LoadTexture("sprites/player.png");
    texture.source = {0, 0, (float) texture.playerSprite.width / 9, (float) texture.playerSprite.height / 3};
    texture.dest = {
    (float) GetScreenWidth() / 2, 
    (float) GetScreenHeight() - (float) texture.source.height / 3, 
    (float) texture.playerSprite.width / 9, 
    (float) texture.playerSprite.height / 3};
    
    texture.origin = {(float) texture.dest.width / 2, texture.dest.height / 2};
}

void Player::Draw(){
    DrawTexturePro(texture.playerSprite, 
    texture.source, 
    texture.dest,
    texture.origin, 
    0, 
    WHITE);
};

void Player::animateWalk(){
    // NOTICE: Funky scaling with spritesheet on export, set dest height to
    // 3x source height

    // Moving right, transition sprite every 7 frames
    if(!Airborne){
        if(playerMoving && frameCount % 7 == 0){
            playerFrame++;
            if(playerFrame >= 8){
                playerFrame = 1;
            }  
        }
        // Idle
        else if(!playerMoving && frameCount % 7 == 0){
            playerFrame = 0;
        }

        // Left Animation
        if(playerDirection == 1){
            texture.source.y = texture.source.height;   //Set to second row of sheet
        }
        else if(playerDirection == 0){
            texture.source.y = 0;
    }

    frameCount++;
    
    // Moves across source sheet, by width per frame
    texture.source.x = texture.source.width * (float) playerFrame;
    }

    else {
        // Animate moving up
        if(speedY == 0){
            texture.source.y = texture.source.height*2;
        }

        // Animate moving down
    }
}

void Player::checkCollision(){
    // Floor Collision
    if(texture.dest.height / 2 + texture.dest.y >= GetScreenHeight()){
        texture.dest.y = GetScreenHeight() - texture.dest.height / 2;
        speedY = 0;
        Airborne = false;
    }

    // Left Wall Collision
    if(texture.dest.x - texture.dest.width / 2 < 0){
        texture.dest.x = texture.dest.width / 2;
    }

    // Right Wall Collision
    else if(texture.dest.x + texture.dest.width / 2 > GetScreenWidth()){
        texture.dest.x =  GetScreenWidth() - texture.dest.width / 2;
    }
};

void Player::updatePos(){
        texture.dest.x += speedX * GetFrameTime();
        texture.dest.y += speedY * GetFrameTime();
}

void Player::horizontalMove(){
    if(IsKeyDown(KEY_RIGHT)){
        playerDirection = 0;
        playerMoving = true;
        speedX = 300;
    }
    else if(IsKeyDown(KEY_LEFT)){
        playerDirection = 1;
        playerMoving = true;
        speedX = -300;
    }
    else{
        playerMoving = false;
        speedX = 0;
    }
};


void Player::verticalMove(){
    
    if(IsKeyPressed(KEY_SPACE) && !Airborne){
        speedY = -1250; 
        Airborne = true;
    }

    // Variable Jump Height
    if(IsKeyReleased(KEY_SPACE) && speedY < 0){
        speedY = 0;
    }

    // Apply Gravity in Air 
    if(Airborne){
        speedY += GRAVITY;
    }

};





