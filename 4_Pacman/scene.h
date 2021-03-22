#pragma once
#include "ecm.h"
class Scene 
{
private:
	float score;
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void update(double dt);
	virtual void render();
	virtual void load() = 0;
	std::vector<std::shared_ptr<Entity>>& getEnts();
	std::shared_ptr<Entity>& getPlayer();
	void updateScore(float p);

protected:
	EntityManager _ents;
	std::shared_ptr<Entity> player;
};