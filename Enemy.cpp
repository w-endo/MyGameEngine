#include "Enemy.h"
#include "Engine/Collider.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy")
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
    transform_.position_.z = 10.0f;

    hModel_ = Model::Load("Assets\\oden.fbx");
    assert(hModel_ >= 0);

    Collider* collision = new Collider(1.2f);
    AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
}

//�`��
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    KillMe();
}
