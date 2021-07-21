#include "SceneManager.h"
#include "../TitleScene.h"
#include "../PlayScene.h"
#include "Model.h"


//�R���X�g���N�^
SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent, "SceneManager")
{
}

//�f�X�g���N�^
SceneManager::~SceneManager()
{
}

//������
void SceneManager::Initialize()
{
    nowScene_ = SCENE_ID_TITLE;
    nextScene_ = SCENE_ID_TITLE;
    Instantiate<TitleScene>(this);
}

//�X�V
void SceneManager::Update()
{
    if (nowScene_ != nextScene_)
    {
        ((GameObject*)*childList_.begin())->KillMe();

        Model::AllRelease();

        switch (nextScene_)
        {
        case SCENE_ID_TITLE: Instantiate<TitleScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;

        }

        nowScene_ = nextScene_;

    }
}

//�`��
void SceneManager::Draw()
{
}

//�J��
void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SCENE_ID nestScene)
{
    nextScene_ = nestScene;
}
