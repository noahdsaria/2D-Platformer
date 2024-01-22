#include "player.h"
#include <math.h>
#include <iostream>

const float GRAVITY = 7.0f;
// Constructor
Player::Player() : 
speedX(0),
speedY(0),
playerDirection(0),
playerMoving(false),
frameCount(0),
playerFrame(1),
Airborne(false)
{};

void Player::Update(){
    speedY = GRAVITY;
    checkInput();
    verticalMove();
    checkCollision();
    // if(IsKeyDown(KEY_SPACE)){
    //     std::cout << "Space is pressed!" << std::endl;
    // }
    animateWalk();
    texture.dest.x += speedX;
    texture.dest.y += speedY;
};

void Player::initPlayerTexture(){
    texture.playerSprite = LoadTexture("sprites/player.png");
    texture.source = {0, 0, (float) texture.playerSprite.width / 9, (float) texture.playerSprite.height / 2};
    texture.dest = {(float) GetScreenWidth() / 2, 0, (float) texture.playerSprite.width / 9, (float) texture.playerSprite.height / 2};
    texture.origin = {(float) texture.dest.width / 2, (float) texture.dest.height / 2};
}

void Player::Draw(){
    DrawTexturePro(texture.playerSprite, texture.source, texture.dest ,texture.origin, 0, WHITE);
};

void Player::checkCollision(){
    // Checks bottom hitbox... Maybe make struct for hitbox!
    if(texture.dest.height /2 + texture.dest.y  >= GetScreenHeight()){
        speedY = 0; 
        texture.dest.y = GetScreenHeight() - texture.dest.height / 2;
        Airborne = false;
    }
};

void Player::checkInput(){
    if(IsKeyDown(KEY_RIGHT)){
        playerDirection = 0;
        playerMoving = true;
        speedX = 4;
    }
    else if(IsKeyDown(KEY_LEFT)){
        playerDirection = 1;
        playerMoving = true;
        speedX = -4;
    }
    else{
        playerMoving = false;
        speedX = 0;
    }
};

void Player::animateWalk(){

    // Moving right, transition sprite every 7 frames
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

    // Choose direction, define negative width to flip left
    if(playerDirection == 1){
        texture.source.width = -fabs(texture.source.width);
    }
    else{
        texture.source.width = fabs(texture.source.width);
    }

    frameCount++;
    
    // Moves across source sheet, by width per frame
    texture.source.x = texture.source.width * (float) playerFrame;
}

void Player::checkAirborne(){
    
    if(speedY != 0){
        Airborne = false;
    }
    else{
        Airborne = true;
    }
};

void Player::verticalMove(){
    if(IsKeyDown(KEY_SPACE) && !Airborne){
        speedY = -50 + GRAVITY*GetFrameTime();
        Airborne = true;
    }

};



