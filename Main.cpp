//インクルード
#include <Windows.h>
#include "Direct3D.h"
//#include "Quad.h"
#include "Dice.h"
#include "Sprite.h"
#include "Camera.h"
#include "Transform.h"
#include "Fbx.h"

//定数宣言
const char* WIN_CLASS_NAME = "SampleGame";  //ウィンドウクラス名
const int CLIENT_WIDTH = 800;  //ウィンドウの幅
const int CLIENT_HEIGHT = 600; //ウィンドウの高さ

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Quad* pQuad;
Dice* pDice;
Sprite* pSprite;
Fbx* pFbx;

//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウクラス（設計図）を作成
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);             //この構造体のサイズ
	wc.hInstance = hInstance;                   //インスタンスハンドル
	wc.lpszClassName = WIN_CLASS_NAME;            //ウィンドウクラス名
	wc.lpfnWndProc = WndProc;                   //ウィンドウプロシージャ
	wc.style = CS_VREDRAW | CS_HREDRAW;         //スタイル（デフォルト）
	wc.hIcon = LoadIcon(NULL, IDI_QUESTION); //アイコン
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //小さいアイコン
	wc.hCursor = LoadCursor(NULL, IDC_WAIT);   //マウスカーソル
	wc.lpszMenuName = NULL;                     //メニュー（なし）
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景（白）

	RegisterClassEx(&wc);  //クラスを登録

	//ウィンドウサイズの計算
	RECT winRect = { 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
	int winW = winRect.right - winRect.left;     //ウィンドウ幅
	int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ

												 //ウィンドウを作成
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,         //ウィンドウクラス名
		"サンプルゲーム",     //タイトルバーに表示する内容
		WS_OVERLAPPEDWINDOW, //スタイル（普通のウィンドウ）
		CW_USEDEFAULT,       //表示位置左（おまかせ）
		CW_USEDEFAULT,       //表示位置上（おまかせ）
		winW,                 //ウィンドウ幅
		winH,                 //ウィンドウ高さ
		NULL,                //親ウインドウ（なし）
		NULL,                //メニュー（なし）
		hInstance,           //インスタンス
		NULL                 //パラメータ（なし）
	);


	//ウィンドウを表示
	ShowWindow(hWnd, nCmdShow);


	//Direct3D初期化
	Direct3D::Initialize(winW, winH, hWnd);

	Camera::Initialize();




	//pQuad = new Quad;
	//if (FAILED(pQuad->Initialize()))
	//{
	//	return 0;
	//}

	pDice = new Dice;
	if (FAILED(pDice->Initialize()))
	{
		return 0;
	}

	pSprite = new Sprite;
	pSprite->Initialize("Assets/dice.png");

	pFbx = new Fbx;
	pFbx->Load("Assets/oden.fbx");

	//メッセージループ（何か起きるのを待つ）
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		//メッセージあり
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//メッセージなし
		else
		{
			//ゲームの処理
			Camera::Update();


			Direct3D::BeginDraw();

			//描画処理
			Transform spriteTrans;
			spriteTrans.position_.x = 0.2f;
			//pSprite->Draw(spriteTrans);


			Transform diceTrans;
			diceTrans.position_.x = 5;
			diceTrans.rotate_.z = 30;
			diceTrans.scale_.x = 2;

			pDice->Draw(diceTrans);

			Transform odenTrans;
			static float angle = 0.0f;
			angle+=0.05;
			odenTrans.rotate_.y = angle;

			static float count = 0;
			count += 0.001;
			//odenTrans.position_.x = sin(count)*3;

			//odenTrans.scale_.y = sin(count)*2 +3;

			pFbx->Draw(odenTrans);

			Direct3D::EndDraw();
		}
	}

	//解放処理
	pFbx->Release();
	SAFE_DELETE(pFbx);

	pDice->Release();
	SAFE_DELETE(pDice);

	pSprite->Release();
	SAFE_DELETE(pSprite);
	
	Direct3D::Release();

	return 0;
}

//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);  //プログラム終了
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}