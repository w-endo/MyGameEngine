#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Collider.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Assets\\oden.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;

    Collider* collision = new Collider(1.2f);
    AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
    transform_.position_.z += 0.5f;

    if (transform_.position_.z > 20)
    {
        KillMe();
    }
}

//�`��
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}