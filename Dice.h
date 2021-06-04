#pragma once
#include "Quad.h"
class Dice :   public Quad
{
	HRESULT CreateVertex() override;	//頂点バッファ作成
	HRESULT CreateIndex() override;		//インデックスバッファ作成
	HRESULT CreateTexture() override;	//テクスチャ作成
};

