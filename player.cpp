#include "player.h"
#include <math.h>
#include <iostream>

const float GRAVITY = 9.8;
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
    checkCollision();
    horizontalMove();
    Jump();
    animateWalk();
    updatePos();
};

void Player::initPlayerTexture(){
    texture.playerSprite = LoadTexture("sprites/player.png");
    texture.source = {0, 0, (float) texture.playerSprite.width / 9, (float) texture.playerSprite.height / 2};
    texture.dest = {
    (float) GetScreenWidth() / 2, 
    (float) GetScreenHeight() - (float) texture.source.height / 2, 
    (float) texture.playerSprite.width / 9, 
    (float) texture.playerSprite.height / 2};
    
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

void Player::checkCollision(){
    // Floor Collision
    if(texture.dest.height / 2 + texture.dest.y >= GetScreenHeight()){
        texture.dest.y = GetScreenHeight() - texture.dest.height / 2;
    }

    // Left Wall Collision
    if(texture.dest.x - texture.dest.width / 2 < 0){
        texture.dest.x = texture.dest.width / 2;
    }

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
        speedX = 200;
    }
    else if(IsKeyDown(KEY_LEFT)){
        playerDirection = 1;
        playerMoving = true;
        speedX = -200;
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
    // FIXME: Animation played in reverse when flipped
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

void Player::Jump(){
};





