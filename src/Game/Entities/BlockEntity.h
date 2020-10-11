#pragma once
#include "ofMain.h"
#include "Entity.h"

class BlockEntity: public Entity{
    public:
        BlockEntity(int, int, int, int, ofImage);
};