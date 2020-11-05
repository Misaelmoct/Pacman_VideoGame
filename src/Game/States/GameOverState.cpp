#include "GameOverState.h"
#include "GameState.h"
#include "Player.h"


GameOverState:: GameOverState(){
	retroGaming.load("Retro_Gaming.ttf",26);
	retroGamingBig.load("Retro_Gaming.ttf", 48);
    gameOverScreen.load("images/GameOverImg.jpg");
    restartButton = new Button(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2, "Restart");

}

void GameOverState:: tick(){
restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("RestartedGameState");
		setFinished(true);

	}
}
void GameOverState::render() {
	gameOverScreen.draw(0, 0, ofGetWidth(), ofGetHeight());
	//restartButton->render();
	retroGamingBig.drawString("SCORE: " + to_string(GameState::mapCopy->getPlayer()->getScore()), ofGetWidth()*1/3.3, ofGetHeight()*1/3);
	retroGaming.drawString("RESTART GAME", ofGetWidth()*.34, ofGetHeight()*3.1/4);

}
void GameOverState::keyPressed(int key){

}

void GameOverState::mousePressed(int x, int y, int button){
restartButton->mousePressed(x, y);
}


void GameOverState::reset(){
	setFinished(false);
	setNextState("");
    restartButton->reset();
}

