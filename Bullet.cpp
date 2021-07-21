#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Collider.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Assets\\oden.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;

    Collider* collision = new Collider(1.2f);
    AddCollider(collision);
}

//更新
void Bullet::Update()
{
    transform_.position_.z += 0.5f;

    if (transform_.position_.z > 20)
    {
        KillMe();
    }
}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}