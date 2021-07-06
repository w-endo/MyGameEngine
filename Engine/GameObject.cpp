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

	�������� void Initialize() ������;
	�������� void Update() ������;
	�������� void Draw() ������;
	�������� void Release() ������;
};