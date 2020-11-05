#include "GhostSpawner.h"



GhostSpawner::GhostSpawner(int x, int y, int width, int height,EntityManager* em, ofImage spriteSheet): Entity(x, y, width, height){
    Ghost* g;
    g->reset();
    for ( int i = 1; i <= 4; i++){
        
        g = new Ghost(x, y, width, height, em, spriteSheet);
        em->entities.push_back(g);
        ghosts.push_back(g);
    }
}

vector <Ghost*> GhostSpawner:: getGhostsVector(){

    return ghosts;
}


