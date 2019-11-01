#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML.h"

class GameObject: public sf::Drawable, public sf::Transformable
{
private:
	std::string m_ID;

protected:


public:
	virtual void InteractWith(GameObject &otherObject);
	GameObject(std::string ID);
	~GameObject();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

#endif