#include "SceneManager.h"
#include "../TitleScene.h"

//コンストラクタ
SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent, "SceneManager")
{
}

//デストラクタ
SceneManager::~SceneManager()
{
}

//初期化
void SceneManager::Initialize()
{
    Instantiate<TitleScene>(this);
}

//更新
void SceneManager::Update()
{
}

//描画
void SceneManager::Draw()
{
}

//開放
void SceneManager::Release()
{
}