#pragma once
#include "Quad.h"
class Dice :   public Quad
{
	HRESULT CreateVertex() override;	//���_�o�b�t�@�쐬
	HRESULT CreateIndex() override;		//�C���f�b�N�X�o�b�t�@�쐬
	HRESULT CreateTexture() override;	//�e�N�X�`���쐬
};

