#include "SceneManager.h"
#include "../TitleScene.h"

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
    Instantiate<TitleScene>(this);
}

//�X�V
void SceneManager::Update()
{
}

//�`��
void SceneManager::Draw()
{
}

//�J��
void SceneManager::Release()
{
}