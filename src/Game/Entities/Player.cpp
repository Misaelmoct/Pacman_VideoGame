#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"

bool Player::ghostIsWeak = false;

Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    retroGaming.load("Retro_Gaming.ttf",18);
    dieSound.load("DIE_SOUND.mp3");
    wakaSound.load("WAKA_SOUND.mp3");
    sprite.load("images/pacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;
    
}
void Player::tick(){
    canMove = true;
    checkCollisions();
    if(canMove){
        if(facing == UP){
            y-= speed;
            walkUp->tick();
        }else if(facing == DOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == LEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == RIGHT){
            x+=speed;
            walkRight->tick();
        }
    }
}

void Player::render(){
    ofSetColor(256,256,256);
    if(facing == UP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }else if(facing == DOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == LEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == RIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }

    // Displays the score on screen throughout the game
    if(this->score >= 0){
        retroGaming.drawString("SCORE: " + to_string(this->score), 300 , 50);
    }

    // Displays the lives Pacman has on screen throughout the game
    if(this->health <= 3){
    retroGaming.drawString("LIVES: " + to_string(this->health), 650 , 50);
    }
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
            setFacing(UP);
            break;
        case 's':
            setFacing(DOWN);
            break;
        case 'a':
            setFacing(LEFT);
            break;
        case 'd':
            setFacing(RIGHT);
            break;
        // Decreases Pacman's lives by 1
        case 'n':
            if (this->health > 0){
                this->die();
            }
            break;
        // Increases Pacman's lives by 1
        case 'm':
            if (this->health < 3){
                this->health = this->health + 1;
            }
            break;
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

void Player::setFacing(FACING facing){
    this->facing = facing;
}

void Player::checkCollisions(){
    for(BlockEntity* block: em->blocks){
        switch(facing){
            case UP:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case DOWN:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case LEFT:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case RIGHT:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
        }
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                entity->remove = true;
            }
        }
    }

    // Raises the score when Pacman eats a dot
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity)){
                this->score = this->score + 10;
                wakaSound.play();
            }
            else if(dynamic_cast<BigDot*>(entity)){
                this->score = this->score + 50;
                wakaSound.play();
                ghostIsWeak = true;
            }
        }
    }

    // Lets Pacman eat Ghosts
    if(ghostIsWeak == true){
        for(Entity* entity:em->entities){
            if(collides(entity)){
                if(dynamic_cast<Ghost*>(entity)){
                    entity->remove = true;
                }
            }
        }
        deathCounter++;
        if(deathCounter >= frameRate*5){
            deathCounter = 0;
            ghostIsWeak = false;
        }
    }
    
    // Lets Ghosts kill Pacman
    if(ghostIsWeak == false){
        for(Entity* entity:em->entities){
            if(collides(entity)){
                if(dynamic_cast<Ghost*>(entity)){
                    this->die();
                }
            }
        }
    }
    
}

// Reduces Pacman’s lives by 1 and resets Pacman to his original location
void Player::die(){
    this->health = this->health - 1;
    Entity::x = xSpawnPosition;
    Entity::y = ySpawnPosition;

    dieSound.play();
}

int Player:: getHealth(){
    return this->health;
}

int Player::getScore(){
    return this->score;
}