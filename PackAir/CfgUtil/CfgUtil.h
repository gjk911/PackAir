#pragma once
#include "../stdafx.h"
#include <fstream>
#include <iostream>

#define INI_LINE_SIZE_MAX 128
#define INI_GROUP_IDENTIFER_STR_L "["
#define INI_GROUP_IDENTIFER_STR_R "]"
#define INI_GROUP_IDENTIFER_C_L '['
#define INI_CHILD_SEPARATOR "="
#define INI_COMMENT_SYMBOL '#'

class CfgUtil
{
public:
	CfgUtil(const char* file);
	char* getValue(const char* group, const char* key);
	virtual ~CfgUtil();
protected:
	//
private:
	const char* fileName;
	std::ifstream cfgStream;
};