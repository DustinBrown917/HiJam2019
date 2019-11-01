#include "Camera.h"
#include "GameObject.h"
#include <iostream>



Camera::Camera(sf::RenderWindow * window_): window(window_)
{
	view.setCenter(sf::Vector2f(1024.f, 1024.f));
	view.setSize(sf::Vector2f(548.f, 548.f));
}

bool Camera::Initialize()
{
	return true;
}

void Camera::Destroy()
{
}

void Camera::HandleEvents(sf::Event event) const
{
	if (event.type == sf::Event::Resized)
	{
		sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
		window->setView(sf::View(visibleArea));
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
