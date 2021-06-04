#include "Dice.h"

HRESULT Dice::CreateVertex()
{
	VERTEX vertices[] =
	{
		//手前 1
		XMVectorSet(-1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// 四角形の頂点（左上）	0
		XMVectorSet(1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// 四角形の頂点（右上）	1
		XMVectorSet(1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// 四角形の頂点（右下）	2
		XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f),	// 四角形の頂点（左下）	3

		//右 2
		XMVectorSet(1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（左上）	4
		XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）	5
		XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（右下）	6
		XMVectorSet(1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）	7

		//左 5
		XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（左上）	8
		XMVectorSet(-1.0f,  1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）	9
		XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f),	XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（右下）	10
		XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）	11

		//奥 6
		XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// 四角形の頂点（左上）	12
		XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// 四角形の頂点（右上）	13
		XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// 四角形の頂点（右下）	14
		XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),	// 四角形の頂点（左下）	15

		//上 3
		XMVectorSet(-1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// 四角形の頂点（左上）	16
		XMVectorSet(1.0f,  1.0f, 1.0f, 0.0f),	XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）	17
		XMVectorSet(1.0f, 1.0f, -1.0f, 0.0f),	XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// 四角形の頂点（右下）	18
		XMVectorSet(-1.0f, 1.0f, -1.0f, 0.0f),	XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）	19

		//下 4
		XMVectorSet(-1.0f,  -1.0f, -1.0f, 0.0f),XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// 四角形の頂点（左上）	20
		XMVectorSet(1.0f,  -1.0f, -1.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）	21
		XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(1.0f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// 四角形の頂点（右下）	22
		XMVectorSet(-1.0f, -1.0f, 1.0f, 0.0f),	XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f),	XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）	23

	};

	// 頂点データ用バッファの設定
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices;


	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_)))
	{
		MessageBox(nullptr, "頂点バッファの作成に失敗しました", "エラー", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

HRESULT Dice::CreateIndex()
{
	int index[] = { 
		0,2,3, 0,1,2,			//手前
		4,6,7, 4,5,6,			//右
		8,10,11, 8,9,10,		//左
		12,14,15, 12,13,14,		//奥
		16,18,19, 16,17,18,		//上
		20,22,23, 20,21,22		//下
	};
	indexCount_ = sizeof(index) / sizeof(int);


	// インデックスバッファを生成する
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(index);
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_)))
	{
		return E_FAIL;
	}
	return S_OK;
}

HRESULT Dice::CreateTexture()
{
	pTexture_ = new Texture;
	if (FAILED(pTexture_->Load("Assets/Dice.png")))
	{
		MessageBox(nullptr, "画像ファイルの読み込みに失敗しました", "エラー", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}
