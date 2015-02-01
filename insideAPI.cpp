#include <stdlib.h>
#include <io.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <vector>
#include "insideAPI.h"
#include "libLogsMacro.h"

LIB_LOGS_BEGIN


#ifdef UNICODE
	typedef std::wstring lib_string;
#else
	typedef std::string lib_string;
#endif


	static void cToLib_string( lib_string& des, const char* src)
{
	assert(nullptr != src);
#ifdef UNICODE

	LPTSTR p = nullptr;
	size_t len = strlen(src) + 1;
	size_t wSize = len * sizeof(wchar_t);
	p = new wchar_t[wSize];
	memset(p, 0, wSize);
	size_t converted = 0;
	mbstowcs_s(&converted, p, len, src, _TRUNCATE);

	des = lib_string(p);
	DELETE_POINT(p);
#else
	des = lib_string(p);
#endif
}


	bool CreateFileDirectory(const char* dirPath)
{
	bool res = true;
	if ( -1 == _access(dirPath, 0))
	{

#ifdef WIN32

		lib_string strPath;
		cToLib_string(strPath, dirPath);

		if (strPath.at(strPath.length() - 1) != LIB_LOGS_SEPARATORY)
		{
			strPath.append(1, LIB_LOGS_SEPARATORY);
		}

		std::vector<lib_string> vPaths;
		lib_string strTemp;

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


		std::vector<lib_string>::iterator itera = vPaths.begin();
		while (itera != vPaths.end())
		{
			res = CreateDirectory(itera->c_str(), NULL) > 0;
			itera++;
		}//end while

#else
		//UINX of LINUX

#endif
	}
	return res;
}

LIB_LOGS_END
