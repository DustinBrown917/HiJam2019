#include "GameScene.h"
#include "Camera.h"
#include "GameObject.h"
#include <iostream>


GameScene::GameScene(sf::RenderWindow * window_) : GameScene(window, "")
{
}

GameScene::GameScene(sf::RenderWindow * window_, std::string backgroundTexture) : window(window_), backgroundTextureName(backgroundTexture)
{
	go = new GameObject("go");
}


GameScene::~GameScene()
{
}

bool GameScene::Initialize() {

	camera = new Camera(window);
	camera->SetAsMainView();
	camera->SetFollowTarget(go);
	
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

	camera->HandleEvents(event);
}

void GameScene::Update() {
	camera->Update();
	go->setPosition(go->getPosition() + sf::Vector2f(0.f, 0.001f));
}

void GameScene::Render() {
	
	window->clear();
	camera->Render();
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
