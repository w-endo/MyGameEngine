#include "Engine/Input.h"
#include "Player.h"
#include "Bullet.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets\\oden.fbx");
}

//�X�V
void Player::Update()
{
    transform_.rotate_.y++;

    if (Input::IsKey(DIK_LEFT))
    {
        transform_.position_.x -= 0.1f;
    }
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.position_.x += 0.1f;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        GameObject *pBullet = Instantiate<Bullet>(pParent_);
        pBullet->SetPosition( transform_.position_);
    }
}

//�`��
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void Player::Release()
{
}