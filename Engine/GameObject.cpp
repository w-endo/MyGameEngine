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

void GameObject::DrawSub()
{
	//©•ª‚ÌDrawŠÖ”‚ğŒÄ‚Ô
	Draw();



}
