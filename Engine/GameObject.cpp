#include "GameObject.h"

GameObject::GameObject() :
	GameObject(nullptr, "")
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	: pParent_(parent),
	objectName_(name),
	isDead(false)
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

	for (auto i = childList_.begin(); i != childList_.end();)
	{
		if ((*i)->isDead)
		{
			(*i)->ReleaseSub();
			delete(*i);
			i = childList_.erase(i);
		}
		else
		{
			i++;
		}
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

	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->ReleaseSub();
		delete(*i);	//©‚ ‚Æ‚ÅSAFE_DELETE‚É•Ï‚¦‚Ä
	}
	childList_.clear();


	Release();

}


void GameObject::KillMe()
{
	isDead = true;
}

GameObject* GameObject::FindChildObject(std::string name)
{
	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		if ((*i)->objectName_ == name)
		{
			return *i;
		}

		GameObject *pObj = (*i)->FindChildObject(name);
		if (pObj)
		{
			return pObj;
		}
	}
	return nullptr;
}

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr)
	{
		return this;
	}
	return pParent_->GetRootJob();
}

GameObject* GameObject::FindObject(std::string name)
{
	return GetRootJob()->FindChildObject(name);
}
