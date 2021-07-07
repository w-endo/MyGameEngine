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
	//Ž©•ª‚ÌUpdateŠÖ”‚ðŒÄ‚Ô
	Update();

	//‚·‚×‚Ä‚ÌŽq‹Ÿ‚ÌUpdateSub‚ðŒÄ‚Ô
	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->UpdateSub();
	}
}

void GameObject::DrawSub()
{
	//Ž©•ª‚ÌDrawŠÖ”‚ðŒÄ‚Ô
	Draw();

	//‚·‚×‚Ä‚ÌŽq‹Ÿ‚ÌDrawSub‚ðŒÄ‚Ô
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
