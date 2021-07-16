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
	//������Update�֐����Ă�
	Update();

	//���ׂĂ̎q����UpdateSub���Ă�
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

	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->ReleaseSub();
		delete(*i);	//�����Ƃ�SAFE_DELETE�ɕς���
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
