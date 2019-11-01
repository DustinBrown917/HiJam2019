#ifndef CAMERA_H
#define CAMERA_H
#include "SFML.h"

class Camera {
private:
	class GameObject* followTarget;
	sf::View view;
	sf::RenderWindow* window;

public:
	Camera(sf::RenderWindow * window_);
	void SetFollowTarget(GameObject *target);
	bool Initialize();
	void Destroy();
	void HandleEvents(sf::Event event);
	void Update();
	void Render();
	void SetAsMainView();
	
};







#endif // !CAMERA_H

