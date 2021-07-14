#pragma once
#include <string>
#include <vector>
#include "Transform.h"
#include "Fbx.h"

namespace Model
{
	struct ModelData
	{
		Fbx* pFbx;
		Transform transform;
		std::string fileName;
	};

	



	//���f�������[�h
	//�����FfileName�@�t�@�C����
	//�ߒl�F���̃��f���f�[�^�Ɋ��蓖�Ă�ꂽ�ԍ�
	int Load(std::string fileName);

	//���[���h�s���ݒ�
	//�����Fhandle		�ݒ肵�������f���̔ԍ�
	//�����Ftransform	�ړ��E��]�E�g����
	//�ߒl�F�Ȃ�
	void SetTransform(int handle, Transform transform);


	void Draw(int handle);
};

