#include "BlockEntity.h"

BlockEntity::BlockEntity(int x, int y, int width, int height, ofImage sprite): Entity(x, y, width, height){
    this->sprite=sprite;
}