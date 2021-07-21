#include "Model.h"

namespace Model
{
    std::vector<ModelData*> datas;
}

int Model::Load(std::string fileName)
{
    ModelData* pModelData = new ModelData;
    pModelData->fileName = fileName;

    bool isExist = false;
    for (int i = 0; i < datas.size(); i++)
    {
        if (datas[i]->fileName == fileName)
        {
            pModelData->pFbx = datas[i]->pFbx;
            isExist = true;
            break;
        }
    }

    if (!isExist)
    {
        pModelData->pFbx = new Fbx;
        pModelData->pFbx->Load(fileName);
    }

    datas.push_back(pModelData);

    return datas.size()-1;
}

void Model::SetTransform(int handle, Transform transform)
{
    datas[handle]->transform = transform;
}

void Model::Draw(int handle)
{
    datas[handle]->pFbx->Draw(datas[handle]->transform);
}

void Model::AllRelease()
{
    for (int i = 0; i < datas.size(); i++)
    {
        datas[i]->pFbx->Release();
        delete(datas[i]->pFbx);
        delete(datas[i]);
    }
    datas.clear();
}
