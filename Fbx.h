#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"

#pragma comment(lib, "LibFbxSDK-MT.lib")
#pragma comment(lib, "LibXml2-MT.lib")
#pragma comment(lib, "zlib-MT.lib")

class Fbx
{
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matW;
	};

	struct VERTEX
	{
		XMVECTOR position;
	};

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;

	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};