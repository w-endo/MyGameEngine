#include "Transform.h"

Transform::Transform()
{
    //メンバ変数６個初期化
}

Transform::~Transform()
{
    //なし
}

void Transform::Calclation()
{
    //移動行列作成
    matTranslate_ = XMMatrixTranslation(position_.m128_f32[0], position_.m128_f32[1], position_.m128_f32[2]);

    //回転行列作成

    //拡大行列作成
}

XMMATRIX Transform::GetWorldMatrix()
{
    return 「移動行列」と「回転行列」と「拡大行列」を合成したやつ;
}
