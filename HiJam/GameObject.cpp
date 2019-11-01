#include "GameObject.h"



void GameObject::InteractWith(GameObject & otherObject)
{
}

GameObject::GameObject(std::string ID)
{
	m_ID = ID;
}


GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

