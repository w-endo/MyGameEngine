#include "Transform.h"

Transform::Transform()
{
    //�����o�ϐ��U������
}

Transform::~Transform()
{
    //�Ȃ�
}

void Transform::Calclation()
{
    //�ړ��s��쐬
    matTranslate_ = XMMatrixTranslation(position_.m128_f32[0], position_.m128_f32[1], position_.m128_f32[2]);

    //��]�s��쐬

    //�g��s��쐬
}

XMMATRIX Transform::GetWorldMatrix()
{
    return �u�ړ��s��v�Ɓu��]�s��v�Ɓu�g��s��v�������������;
}
