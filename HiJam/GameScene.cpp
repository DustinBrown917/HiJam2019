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

	return true;
}

void GameScene::Destroy() {

}

void GameScene::HandleEvents(sf::Event event) const {

}

void GameScene::Update() {
}

void GameScene::Render() {
	window->clear();
	window->draw(shape);
	window->display();
}