#pragma once

#include "State.h"
#include "Button.h"
#include "Player.h"

class GameOverState: public State{

    private:
	ofImage gameOverScreen;
	Button *restartButton;


    public:

	GameOverState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};