#include "Camera.h"
#include "GameObject.h"
#include <iostream>



Camera::Camera(sf::RenderWindow * window_): window(window_)
{
	view.setCenter(sf::Vector2f(1024.f, 1024.f));
	view.setSize(sf::Vector2f(1048.f, 1048.f));
}

bool Camera::Initialize()
{
	return true;
}

void Camera::Destroy()
{
}

void Camera::HandleEvents(sf::Event event)
{
	if (event.type == sf::Event::Resized)
	{
		view.setSize(sf::Vector2f(event.size.width, event.size.height));
		SetAsMainView();
	}
	
	
}

void Camera::Update()
{
	if (followTarget) {
		view.setCenter(followTarget->getPosition());
		SetAsMainView();
	}
}

void Camera::Render()
{
}

void Camera::SetAsMainView()
{
	window->setView(view);
}



void Camera::SetFollowTarget(GameObject *target)
{
	followTarget = target;
}
