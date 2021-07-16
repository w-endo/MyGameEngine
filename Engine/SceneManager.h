#pragma once
#include "GameObject.h"

//◆◆◆を管理するクラス
class SceneManager : public GameObject
{

public:
    //コンストラクタ
    SceneManager(GameObject* parent);

    //デストラクタ
    ~SceneManager();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};