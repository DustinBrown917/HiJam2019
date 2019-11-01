#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML.h"

class GameObject: public sf::Drawable, public sf::Transformable
{
private:
	std::string m_ID;

public:
	virtual void InteractWith(GameObject &otherObject) = 0;
	GameObject(std::string ID);
	~GameObject();
};

#endif