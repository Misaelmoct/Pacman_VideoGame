#include "GameState.h"
#include "Entity.h"
Map* GameState::mapCopy = NULL;

GameState::GameState() {
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
	
}
void GameState::tick() {

	int health = map->getPlayer()->getHealth(); 
	if(health == 0){ 
	setNextState("GameOverState");
	setFinished(true);
	}
	map->tick();
	mapCopy = map;
}
void GameState::render() {
	map->render();

}

void GameState::keyPressed(int key){
	map->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}
Map* GameState::getMap(){
	return mapCopy;
}