#include "Map.h"

Map::Map(EntityManager* em){
    entityManager = em;
}

void Map::tick(){
	entityManager->tick();
	player->tick();

}
void Map::render(){
    ofSetBackgroundColor(0, 0, 0);
	entityManager->render();
	player->render();

}

void Map::keyPressed(int key){
	player->keyPressed(key);
	int a = round(ofRandom(0, 3));
	spawn->getGhostsVector()[a]->keyPressed(key);
}

void Map::mousePressed(int x, int y, int button){
	player->mousePressed(x, y, button);
}

void Map::keyReleased(int key){
	player->keyReleased(key);
}
void Map::addBlockEntity(BlockEntity* e){
    entityManager->blocks.push_back(e);
}
void Map::addEntity(Entity* e){
	entityManager->entities.push_back(e);
}
void Map::setPlayer(Player* p){
    player = p;
}

Player* Map::getPlayer(){
    return this->player;
}

void Map::setSpawn(GhostSpawner* s){
	this->spawn = s;
}

GhostSpawner* Map:: getSpawn(){
	return this->spawn;
}