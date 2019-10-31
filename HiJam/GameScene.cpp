#include "GameScene.h"
#include <iostream>


GameScene::GameScene(sf::RenderWindow * window_) : window(window_)
{
}


GameScene::~GameScene()
{
}

bool GameScene::Initialize() {
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);

	view.setCenter(sf::Vector2f(1024.f, 1024.f));
	view.setSize(sf::Vector2f(2048.f, 2048.f));

	if (!backgroundTexture.loadFromFile("GrasslandTiles.png")) {
		std::cout << "Could not load background image.";
		Destroy();
		return false;
	}

	backgroundSprite.setTexture(backgroundTexture);

	return true;
}

void GameScene::Destroy() {

}

void GameScene::HandleEvents(sf::Event event) const {

}

void GameScene::Update() {
}

void GameScene::Render() {
	window->setView(view);
	window->clear();
	//window->draw(shape);
	window->draw(backgroundSprite);
	window->display();
}