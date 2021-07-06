#pragma once

#include <string>
#include <list>
#include "Transform.h"

class GameObject
{
	std::list<GameObject*> childList_;
	Transform	transform_;
	GameObject*	pParent_;
	std::string	objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	œœœœ void Initialize() œœœ;
	œœœœ void Update() œœœ;
	œœœœ void Draw() œœœ;
	œœœœ void Release() œœœ;
};