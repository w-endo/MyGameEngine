#pragma once
#include <DirectXMath.h>

using namespace DirectX;

#define vecX  m128_f32[0]
#define vecY  m128_f32[1]
#define vecZ  m128_f32[2]


//�ʒu�A�����A�g�嗦�Ȃǂ��Ǘ�����N���X
class Transform
{
	XMMATRIX matTranslate_;	//�ړ��s��
	XMMATRIX matRotate_;	//��]�s��	
	XMMATRIX matScale_;	//�g��s��

public:
	XMVECTOR position_;	//�ʒu
	XMVECTOR rotate_;	//����
	XMVECTOR scale_;	//�g�嗦

	//�R���X�g���N�^
	Transform();

	//�f�X�g���N�^
	~Transform();

	//�e�s��̌v�Z
	void Calclation();

	//���[���h�s����擾
	XMMATRIX GetWorldMatrix();
};