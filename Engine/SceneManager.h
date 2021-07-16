#pragma once
#include "GameObject.h"

//���������Ǘ�����N���X
class SceneManager : public GameObject
{

public:
    //�R���X�g���N�^
    SceneManager(GameObject* parent);

    //�f�X�g���N�^
    ~SceneManager();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};