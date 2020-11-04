#pragma once
#include "Entity.h"
#include "Animation.h"
#include "EntityManager.h"

enum GFACING {
    gUP,
    gDOWN,
    gLEFT,
    gRIGHT
};
class Ghost: public Entity{
    private:
    int ghostNo = 0;
    static int ghostCount;
    int speed = 0;
    static int uniqSpeed;
    bool walking = false;
    GFACING facing = gUP;
    ofImage up, down, left, right;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;
    EntityManager* em;
    bool canMove;


    public:
        Ghost(int, int, int, int,EntityManager*, ofImage);
        void die();
        void setFacing(GFACING facing);
        int getGhostNo();
        //static int getGhostCount();
        void checkCollisions();
        void tick();
        void render();
        GFACING getFacing();
        vector <GFACING> paths(BlockEntity* b);
        int xSpawnPoint = Entity::x;
        int ySpawnPoint = Entity::y;
        void reset();
        
};

/*static int Ghost:: getGhostCount(){
    return ghostCount;
}*/