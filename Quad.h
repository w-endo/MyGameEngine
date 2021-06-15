#pragma once
#include <DirectXMath.h>
#include "Direct3D.h"
#include "Texture.h"
#include "Transform.h"

using namespace DirectX;

//�R���X�^���g�o�b�t�@�[
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX	matW;
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;
};

class Quad
{
protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@	
	Texture* pTexture_;				//�e�N�X�`��
	int indexCount_;				//�C���f�b�N�X���̐�


	virtual HRESULT CreateVertex();		//���_�o�b�t�@�쐬
	virtual HRESULT CreateIndex();		//�C���f�b�N�X�o�b�t�@�쐬
	virtual HRESULT CreateConstant();	//�R���X�^���g�o�b�t�@�쐬
	virtual HRESULT CreateTexture();	//�e�N�X�`���쐬


public:
	Quad();
	~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(Transform transform);
	virtual void Release();
};