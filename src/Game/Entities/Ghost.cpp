#include "Ghost.h"
#include <vector>
#include "EntityManager.h"

int Ghost:: ghostCount = 0;
int Ghost:: uniqSpeed = 0;

Ghost:: Ghost(int x, int y, int width, int height, EntityManager* em):Entity(x, y, width, height){
this->em = em;
ghostNo = ++ghostCount;

}
Ghost::Ghost(int x, int y, int width, int height, EntityManager* em, ofImage spriteSheet): Entity(x, y, width, height){
    this->em = em;

    speed = ++uniqSpeed;
    ghostNo = ++ghostCount;
    sprite = spriteSheet;
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    int xPosImage = 456;
    int yPosImage;
    ofImage temp;
    switch (this->ghostNo){
    case 2:
        yPosImage = 80;
        break;
    case 3:
        yPosImage = 96;
        break;
    case 4:
        yPosImage = 112;
        break;
    
    
    case 1:
        yPosImage = 64;
        break;
    }
        for(int i = 96 ; i <= 112; i+=16){
        temp.cropFrom(sprite,xPosImage + i, yPosImage, 16, 16);
        downAnimframes.push_back(temp);
    }

        for(int i = 64 ; i <= 80; i+=16){
        temp.cropFrom(sprite,xPosImage + i, yPosImage, 16, 16);
        upAnimframes.push_back(temp);
    }

        for(int i = 32 ; i <= 48; i+=16){
        temp.cropFrom(sprite,xPosImage + i, yPosImage, 16, 16);
        leftAnimframes.push_back(temp);
    }   

        for(int i = 0 ; i <= 16; i+=16){
        temp.cropFrom(sprite,xPosImage + i, yPosImage, 16, 16);
        rightAnimframes.push_back(temp);
    }

    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

}


void Ghost:: reset(){
    uniqSpeed = 0;
    ghostCount = 0;
}


void Ghost:: tick(){
    checkCollisions();
        if(facing == gUP){
            y-= speed;
            walkUp->tick();
        }else if(facing == gDOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == gLEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == gRIGHT){
            x+=speed;
            walkRight->tick();
        }

}

void Ghost:: render(){
    ofSetColor(256,256,256);
    if(facing == gUP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }else if(facing == gDOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == gLEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == gRIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }
}

void Ghost:: keyPressed(int key){
    if(key == 'g'){
    Ghost* g = new Ghost(xSpawnPoint, ySpawnPoint, width, height, em);
    g->walkUp = this->walkUp;
    g->walkDown = this->walkDown;
    g->walkLeft = this->walkLeft;
    g->walkRight = this->walkRight;
    g->speed = this->speed;
    em->entities.push_back(g);
    }
}

void Ghost::checkCollisions(){

    for(BlockEntity* block: em->blocks){
    vector <GFACING> paths;

    if (this->getBounds(x, y-speed).intersects(block->getBounds()) == false){ paths.push_back(gUP); }
    if (this->getBounds(x, y+speed).intersects(block->getBounds()) == false){ paths.push_back(gDOWN); }
    if (this->getBounds(x-speed, y).intersects(block->getBounds()) == false){ paths.push_back(gLEFT); }
    if (this->getBounds(x+speed, y).intersects(block->getBounds()) == false){ paths.push_back(gRIGHT); }


        switch(facing){

            case gUP:

                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                int j = round(ofRandom(0, (paths.size() - 1)));
                setFacing(paths[j]);
                if (Entity::y > ySpawnPoint - 64 && Entity::y < ySpawnPoint && Entity::x == xSpawnPoint){    
                   if (this->facing == gDOWN){
                       if(j == 0){
                       setFacing(gRIGHT);
                       }
                       else{setFacing(gLEFT);}
                   }
                }
                    this->checkCollisions();
                }
                break;
            case gDOWN:

                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                int j = round(ofRandom(0, (paths.size() - 1)));
                setFacing(paths[j]);                   
                    this->checkCollisions();
                }
                break;
            case gLEFT:

               if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                int j = round(ofRandom(0, (paths.size() - 1)));
                setFacing(paths[j]);                   
                    this->checkCollisions();
                }
                break;
            case gRIGHT:

                if(this->getBounds(x+speed, y).intersects(block->getBounds())){

                int j = round(ofRandom(0, (paths.size() - 1)));
                setFacing(paths[j]);                   
                    this->checkCollisions();
                }
                break;
        }
    }
}


void Ghost::setFacing(GFACING facing){
    this->facing = facing;
}

GFACING Ghost:: getFacing(){
    return this->facing;
}

int Ghost:: getGhostNo(){
    return this->ghostNo;
}

int Ghost:: getGhostCount(){
    return ghostCount;
}

void Ghost:: setGhostCount(int c){
    ghostCount = c;
}


