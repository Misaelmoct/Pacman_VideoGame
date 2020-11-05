#pragma once
#include "Player.h"
#include "GhostSpawner.h"

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
      void setSpawn(GhostSpawner*);
      GhostSpawner* getSpawn();

    private:
      EntityManager *entityManager;
      Player *player;
      GhostSpawner *spawn;
};