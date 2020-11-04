#include "GameOverState.h"


GameOverState:: GameOverState(){

    gameOverScreen.load("images/GameOverImg.jpg");
    restartButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Restart");
}

void GameOverState:: tick(){
restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("RestartedGameState");
		setFinished(true);

	}
}
void GameOverState::render() {
	//ofSetBackgroundColor(230, 230, 250);
	gameOverScreen.draw(0, 0, ofGetWidth(), ofGetHeight());
	//restartButton->render();
	
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