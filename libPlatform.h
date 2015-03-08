/************************************************************************/
/* About different platforms.                                            */
/************************************************************************/

#ifndef LIB_LOGS_PLATFORM_H
#define LIB_LOGS_PLATFORM_H


#define LIB_LOGS_BEGIN namespace LibLogs {
#define LIB_LOGS_END }

#ifdef WIN32

#include <windows.h>
#include <tchar.h>
#include <io.h>

#ifdef LIB_LOGS_EXPORTS
#define LIB_LOGS_API __declspec(dllexport)
#else
#define LIB_LOGS_API __declspec(dllimport)
#endif

#define libLog_localtime(ptm, lt) localtime_s((ptm), &(lt))
#define LIB_LOGS_SEPARATORY '\\'


#else

// other os eg,unix or linux

#include <unistd.h>
#include <sys/stat.h>

#define LIB_LOGS_API

#define libLog_localtime(ptm, lt) localtime_r(&(lt), (ptm))
#define LIB_LOGS_SEPARATORY '/'
#endif


#define LIB_LOGS_INTERFACE struct


#endif


