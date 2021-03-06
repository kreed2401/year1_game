#pragma once
#include <memory>
#include "scene.h"
#include "game.h"


extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;


class MenuScene : public Scene 
{
private:
	sf::Text text;

public:
	MenuScene() = default;
	void update(double dt) override;
	void render() override;
	void load()override;
};

class GameScene : public Scene 
{
private:
	sf::Text text;
	sf::Clock scoreClock;
	void respawn();
	
	std::vector<std::shared_ptr<Entity>> ghosts;
	float score;
public:
	GameScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
	void updateScore(float p);
};