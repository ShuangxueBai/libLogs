/************************************************************************/
/* 这里集合一些与平台相关的内容                                                                                   */
/************************************************************************/

#ifndef LIB_LOGS_PLATFORM_H
#define LIB_LOGS_PLATFORM_H


#define LIB_LOGS_BEGIN namespace LibLogs {
#define LIB_LOGS_END }

#ifdef WIN32

#include <windows.h>

//DLL
#ifdef LIB_LOGS_EXPORTS
#define LIB_LOGS_API __declspec(dllexport)
#else
#define LIB_LOGS_API __declspec(dllimport)
#endif

#else
//非DLL
#include <unistd.h>
#define LIB_LOGS_API
#endif


#ifdef WIN32
#define LIB_LOGS_SEPARATORY '\\'
#else
#define LIB_LOGS_SEPARATORY '/'
#endif 


#define LIB_LOGS_INTERFACE struct


#endif


