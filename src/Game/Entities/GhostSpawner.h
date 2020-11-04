#pragma once
#include "Entity.h"
#include "Ghost.h"
#include <vector>
#include "Map.h"


class GhostSpawner: public Entity{
    private:
    vector <Ghost*> ghosts;

    
    public:
        GhostSpawner(int, int, int, int,EntityManager*, ofImage);
        vector <Ghost*> getGhostsVector();
        

};