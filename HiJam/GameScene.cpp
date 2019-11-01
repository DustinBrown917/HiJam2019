#include "GameScene.h"
#include <iostream>


GameScene::GameScene(sf::RenderWindow * window_) : GameScene(window, "")
{
}

GameScene::GameScene(sf::RenderWindow * window_, std::string backgroundTexture) : window(window_), backgroundTextureName(backgroundTexture)
{
}


GameScene::~GameScene()
{
}

bool GameScene::Initialize() {

	view.setCenter(sf::Vector2f(1024.f, 1024.f));
	view.setSize(sf::Vector2f(2048.f, 2048.f));
	
	if (backgroundTextureName != "") {
		if (!SetBackground(backgroundTextureName)) {
			Destroy();
			return false;
		}
	}

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
	window->draw(backgroundSprite);
	window->display();
}

bool GameScene::SetBackground(std::string textureName)
{
	if (!backgroundTexture.loadFromFile(textureName)) {
		std::cout << "Could not load background image.";
		return false;
	}

	backgroundSprite.setTexture(backgroundTexture);
	return true;
}
