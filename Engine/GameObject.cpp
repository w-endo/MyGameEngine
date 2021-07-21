#include "GameObject.h"

GameObject::GameObject() :
	GameObject(nullptr, "")
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	: pParent_(parent),
	objectName_(name),
	isDead(false),
	pCollider_(nullptr)
{
	childList_.clear();
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	//自分のUpdate関数を呼ぶ
	Update();

	//すべての子供のUpdateSubを呼ぶ
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

			RecursiveCollison()

		}
	}

}

void GameObject::DrawSub()
{
	//自分のDraw関数を呼ぶ
	Draw();

	//すべての子供のDrawSubを呼ぶ
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
		delete(*i);	//←あとでSAFE_DELETEに変えて
	}
	childList_.clear();


	Release();

}


void GameObject::KillMe()
{
	isDead = true;
}

void GameObject::AddCollider(Collider* pCollider)
{
	pCollider_ = pCollider;
}

void GameObject::RecursiveCollison(GameObject* pTarget)
{








}

void GameObject::Collision(GameObject* pTarget)
{
	float x = transform_.position_.x - pTarget->transform_.position_.x;
	float y = transform_.position_.y - pTarget->transform_.position_.y;
	float z = transform_.position_.z - pTarget->transform_.position_.z;
	float r = pCollider_->GetRadius() + pTarget->pCollider_->GetRadius();

	if (x * x + y * y + z * z < r * r)
	{
		int a = 0;
	}
}
