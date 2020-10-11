#pragma once

#include "BlockEntity.h"

class EntityManager {

public:

	std::vector<Entity*> entities;
	std::vector<BlockEntity*>blocks;
	void tick();
	void render();

};