#pragma once
#include "Scene.h"
class GameScene : public Scene
{
private:
	sf::RenderWindow * window;

	sf::CircleShape shape;

public:
	GameScene(sf::RenderWindow * window_);
	~GameScene();

	bool Initialize();
	void Destroy();
	void HandleEvents(sf::Event event) const;
	void Update();
	void Render();
};

