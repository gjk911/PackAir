// PackAir.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>

#include "CfgUtil/CfgUtil.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//(ANSI)
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"wmainCRTStartup\"" )//(UNICODE)

using namespace std;

void SetCurDir()
{
	TCHAR filePath[MAX_PATH];
	::GetModuleFileName(NULL, filePath, MAX_PATH);
	std::basic_string<TCHAR> path = filePath;
	path = path.substr(0, path.find_last_of(TEXT("\\")));
	::SetCurrentDirectory(path.c_str());
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetCurDir();

	const char * cfgFile = "app.ini";
	CfgUtil* cfg = new CfgUtil(cfgFile);
	string loc_adl = cfg->getValue("base", "loc_adl");
	string loc_app_xml = cfg->getValue("base", "loc_app_xml");
	string run_args = cfg->getValue("base", "run_args");

	const string SPACE = TEXT(" ");

	::WinExec((loc_adl + SPACE + loc_app_xml + SPACE + run_args).c_str(), SW_HIDE);

	//while('x' != getchar()){};
	return 0;
}

