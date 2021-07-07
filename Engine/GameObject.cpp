#include "GameObject.h"

GameObject::GameObject() :
	GameObject(nullptr, "")
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	: pParent_(parent),
	objectName_(name)
{
	childList_.clear();
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	//������Update�֐����Ă�
	Update();

	//���ׂĂ̎q����UpdateSub���Ă�
	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->UpdateSub();
	}
}

void GameObject::DrawSub()
{
	//������Draw�֐����Ă�
	Draw();

	//���ׂĂ̎q����DrawSub���Ă�
	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->DrawSub();
	}

}

void GameObject::ReleaseSub()
{
	Release();

	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->ReleaseSub();
	}
}
