#include "Enemy.h"
#include "Engine/Collider.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy")
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    transform_.position_.z = 10.0f;

    hModel_ = Model::Load("Assets\\oden.fbx");
    assert(hModel_ >= 0);

    Collider* collision = new Collider(1.2f);
    AddCollider(collision);
}

//更新
void Enemy::Update()
{
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    KillMe();
}
