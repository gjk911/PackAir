#include "stdafx.h"
#include "CfgUtil.h"

CfgUtil::CfgUtil(const char* file):cfgStream(file)
{
	
};

CfgUtil::~CfgUtil()
{

};

char* CfgUtil::getValue(const char* group, const char* key)
{
	if( !cfgStream )
	{
		return "";
	}

	cfgStream.clear();
	cfgStream.seekg(0, std::ios_base::beg);

	char strGroup[INI_LINE_SIZE_MAX] = {0};
	strcat_s(strGroup, INI_LINE_SIZE_MAX, INI_GROUP_IDENTIFER_STR_L);
	strcat_s(strGroup, INI_LINE_SIZE_MAX, group);
	strcat_s(strGroup, INI_LINE_SIZE_MAX, INI_GROUP_IDENTIFER_STR_R);
	
	char buf[INI_LINE_SIZE_MAX] = {0};
	bool bFind = false;

	while( cfgStream.getline(buf, INI_LINE_SIZE_MAX) )
	{
		if(buf[0] == INI_GROUP_IDENTIFER_C_L)
		{
			if(0 == strcmp(buf, strGroup))
			{
				bFind = true;
				continue;
			}
		}
		else if(buf[0] == INI_COMMENT_SYMBOL)
		{
			continue;
		}
		else
		{
			if(bFind)
			{
				char* valBuf;
				char* curKey = strtok_s(buf, INI_CHILD_SEPARATOR, &valBuf);
				if(0 == strcmp(curKey, key))
				{
					bFind = false;
					int resLen = strlen(valBuf) * sizeof(char) + 1;
					char* result = (char*)malloc(resLen);
					memset(result, 0, resLen);
					strcpy(result, valBuf);
					return result;
				}
				continue;
			}
			continue;
		}
	}
	
	return "";
};