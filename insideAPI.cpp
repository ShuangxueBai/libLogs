#include "insideAPI.h"
#include <stdlib.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <vector>

LIB_LOGS_BEGIN


	static void cTow(LPTSTR des, const char* src, size_t len)
{
#ifdef UNICODE
	size_t converted = 0;
	mbstowcs_s(&converted, des, len, src, _TRUNCATE);
#else
	des = (LPTSTR)src;
#endif
}


	bool CreateFileDirectory(const char* dirPath)
{
	bool res = true;

#ifdef WIN32
	LPTSTR pDirPath = NULL;

	size_t len = strlen(dirPath) + 1;
	size_t wSize = len * sizeof(wchar_t);
	size_t converted = 0;
	pDirPath  = new wchar_t[wSize];
	memset(pDirPath, 0, wSize);
	cTow(pDirPath, dirPath, len);

	std::wstring strPath = pDirPath;
	if(pDirPath != (LPTSTR)dirPath && NULL != pDirPath)
	{
			delete[] pDirPath;
			pDirPath = NULL;
	}

	if (strPath.at(strPath.length() - 1) != LIB_LOGS_SEPARATORY)
	{
		strPath.append(1, LIB_LOGS_SEPARATORY);
	}

	std::vector<std::wstring> vPaths;
	std::wstring strTemp;
	
	for (size_t i = 0; i < strPath.length(); ++i)
	{
		if (strPath.at(i) != LIB_LOGS_SEPARATORY)
		{
			strTemp.append(1, strPath.at(i));
		}
		else
		{
			vPaths.push_back(strTemp);
			strTemp.append(1, LIB_LOGS_SEPARATORY);
		}
	}//end for


	std::vector<std::wstring>::iterator itera = vPaths.begin();
	while (itera != vPaths.end())
	{
		res = CreateDirectory(itera->c_str(), NULL) > 0;
		itera++;
	}//end while

#else
	//UINX of LINUX

#endif
	return res;
}

LIB_LOGS_END
