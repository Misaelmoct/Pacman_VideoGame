#include "MenuState.h"

MenuState::MenuState() {
	img1.load("images/startScreen.jpg");
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight(), "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	//ofSetBackgroundColor(230, 230, 250);
	img1.draw(0, 0, ofGetWidth(), ofGetHeight());
	//startButton->render();
	
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}