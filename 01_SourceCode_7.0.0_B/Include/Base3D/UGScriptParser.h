//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.1           
//                                                           
//!  \file UGMaterial.h
//!  \brief ��ά���ʽű�������
//!  \details ��ɲ��ʽű��Ľ���
//!  \author sunyl
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.1
//////////////////////////////////////////////////////////////////////////

#ifndef __SCRIPTPARSER_H__
#define __SCRIPTPARSER_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGScriptCompiler.h"
#include "Base3D/UGScriptLexer.h"

namespace UGC
{

//! \brief ��ά�����ࡣ
class BASE3D_API UGScriptParser
{
public:
	//! \brief ���캯����
	UGScriptParser();
	//! \brief ���캯����
	virtual ~UGScriptParser(){}

	ConcreteNodeListPtr parse(const ScriptTokenListPtr &tokens);
	ConcreteNodeListPtr parseChunk(const ScriptTokenListPtr &tokens);
private:
	ScriptToken *getToken(ScriptTokenList::iterator i, ScriptTokenList::iterator end, UGint offset);
	ScriptTokenList::iterator skipNewlines(ScriptTokenList::iterator i, ScriptTokenList::iterator end);


} ;
}

#endif 


