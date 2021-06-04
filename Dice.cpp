#include "Dice.h"

HRESULT Dice::CreateVertex()
{
	VERTEX vertices[] =
	{
		//��O 1
		XMVectorSet(-1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// �l�p�`�̒��_�i����j	0
		XMVectorSet(1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// �l�p�`�̒��_�i�E��j	1
		XMVectorSet(1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// �l�p�`�̒��_�i�E���j	2
		XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// �l�p�`�̒��_�i�����j	3

		//�E 2
		XMVectorSet(1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j	4
		XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j	5
		XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j	6
		XMVectorSet(1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j	7

		//�� 5
		XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j	8
		XMVectorSet(-1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j	9
		XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j	10
		XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j	11

		//�� 6
		XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// �l�p�`�̒��_�i����j	12
		XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// �l�p�`�̒��_�i�E��j	13
		XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// �l�p�`�̒��_�i�E���j	14
		XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// �l�p�`�̒��_�i�����j	15

		//�� 3
		XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j	16
		XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j	17
		XMVectorSet(1.0f, 1.0f, -1.0f, 0.0f),	XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j	18
		XMVectorSet(-1.0f, 1.0f, -1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j	19

		//�� 4
		XMVectorSet(-1.0f,  -1.0f, -1.0f, 0.0f),XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j	20
		XMVectorSet(1.0f,  -1.0f, -1.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j	21
		XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(1.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j	22
		XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j	23

	};

	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices;


	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_)))
	{
		MessageBox(nullptr, "���_�o�b�t�@�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

HRESULT Dice::CreateIndex()
{
	int index[] = { 
		0,2,3, 0,1,2,			//��O
		4,6,7, 4,5,6,			//�E
		8,10,11, 8,9,10,		//��
		12,14,15, 12,13,14,		//��
		16,18,19, 16,17,18,		//��
		20,22,23, 20,21,22		//��
	};
	indexCount_ = sizeof(index) / sizeof(int);


	// �C���f�b�N�X�o�b�t�@�𐶐�����
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(index);
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_)))
	{
		return E_FAIL;
	}
	return S_OK;
}

HRESULT Dice::CreateTexture()
{
	pTexture_ = new Texture;
	if (FAILED(pTexture_->Load("Assets/Dice.png")))
	{
		MessageBox(nullptr, "�摜�t�@�C���̓ǂݍ��݂Ɏ��s���܂���", "�G���[", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}
