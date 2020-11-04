#include "GhostSpawner.h"



GhostSpawner::GhostSpawner(int x, int y, int width, int height,EntityManager* em, ofImage spriteSheet): Entity(x, y, width, height){
    
    for ( int i = 1; i <= 4; i++){
        
        Ghost* g = new Ghost(x, y, width, height, em, spriteSheet);
        em->entities.push_back(g);
    }
}

vector <Ghost*> GhostSpawner:: getGhostsVector(){

    return ghosts;
}
/*ofImage ghostSpriteGenerator(ofImage imgGhost){
        
        for(int i = 0; i < 48; i + 16 ){
        sprite.cropFrom(imgGhost, 456, 64 + i, 16, 16)
    }*/


