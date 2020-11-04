#include "GhostSpawner.h"



GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    
    for ( int i = 0; i <= 48; i+=16){
        
        sprite1.cropFrom(spriteSheet, 456, 64 + i, 16, 16);
        Ghost* g = new Ghost(x, y, width, height, sprite1);
        ghosts.push_back(g);
    }
}

/*GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){

    sprite1.cropFrom(spriteSheet, 456, 64, 16, 16)
    Ghost* g1 = new Ghost(x, y, width, height, sprite1)
    sprite1.cropFrom(spriteSheet, 456, 80, 16, 16)
    Ghost* g1 = new Ghost(x, y, width, height, sprite1)
    sprite1.cropFrom(spriteSheet, 456, 96, 16, 16)
    Ghost* g1 = new Ghost(x, y, width, height, sprite1)
    sprite1.cropFrom(spriteSheet, 456, 112, 16, 16)
    Ghost* g1 = new Ghost(x, y, width, height, sprite1)

}*/

vector <Ghost*> GhostSpawner:: getGhostsVector(){

    return ghosts;
}
/*ofImage ghostSpriteGenerator(ofImage imgGhost){
        
        for(int i = 0; i < 48; i + 16 ){
        sprite.cropFrom(imgGhost, 456, 64 + i, 16, 16)
    }*/


