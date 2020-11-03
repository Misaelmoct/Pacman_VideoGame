#pragma once
#include "Player.h"

class Map{
    public:
      Map(EntityManager*);
      void addBlockEntity(BlockEntity*);
      void addEntity(Entity*);
      void setPlayer(Player*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);
      Player* getPlayer();

    private:
      EntityManager *entityManager;
      Player *player;
};