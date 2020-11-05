#include "MenuState.h"

MenuState::MenuState() {
	retroGaming.load("Retro_Gaming.ttf",32);
	img1.load("images/GhostSanta.jpg");
	startButton = new Button(0, 0, ofGetWidth(), ofGetHeight(), "Start");
	
	int num = 1500;
	p.assign(num, Particle());

	resetParticles();
}


void MenuState::resetParticles(){

	//these are the attraction points used in the fourth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
	}
	
	attractPointsWithMovement = attractPoints;
	
	for(unsigned int i = 0; i < p.size(); i++){		
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}





void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}

	for(unsigned int i = 0; i < p.size(); i++){
				p[i].update();
			}

	for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
	}
}
void MenuState::render() {
	ofSetBackgroundColor(0, 0, 0);
	img1.draw(ofGetWidth()/2 - 275, ofGetHeight()/2 - 154.5, 550, 309);
	retroGaming.drawString("PRESS TO START", ofGetWidth()*1/3.2, ofGetHeight()*3/4);
	//startButton->render();


	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}
	
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