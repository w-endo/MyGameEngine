#pragma once
#include "GameObject.h"

//�Q�[���ɓo�ꂷ��V�[��
enum SCENE_ID
{
    SCENE_ID_TITLE = 0,
    SCENE_ID_PLAY,
};

//���������Ǘ�����N���X
class SceneManager : public GameObject
{
    SCENE_ID nowScene_;
    SCENE_ID nextScene_;

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

    void ChangeScene(SCENE_ID nestScene);
};