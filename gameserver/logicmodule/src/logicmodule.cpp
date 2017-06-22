//
// Created by DGuco on 17-6-21.
//

#include "../inc/logicmodule.h"

CLogicModule::CLogicModule()
{
    mRegist = false;
    mModueType = EMODULETYPE_INVALID;
}

CLogicModule::~CLogicModule()
{

}

bool CLogicModule::IsRegist()
{
    return mRegist;
}

void CLogicModule::RegistModule(EModuleType eType)
{
    mRegist = true;
    mModueType = eType;
}
