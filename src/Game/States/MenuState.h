#pragma once

#include "State.h"
#include "Button.h"
#include "Particle.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;

public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void resetParticles();

	vector <Particle> p;
	vector <glm::vec3> attractPoints;
	vector <glm::vec3> attractPointsWithMovement;
	ofTrueTypeFont retroGaming;
};
