/************************************************************************/
/* libLogs用于产生一个可以扩展和用户定制的日志操作库函数。                                */
/************************************************************************/

#ifndef LIB_LOGS_H
#define LIB_LOGS_H

#include "libPlatform.h"

LIB_LOGS_BEGIN

	enum LogsType
{
	TIME_SHARE = 0

};

 LIB_LOGS_INTERFACE LIB_LOGS_API LibLogsSystem
{
	virtual void setSaveDir(const char* logsFileDir) = 0;
	virtual void setLogFileMaxSize(const int& maxSize_kb) = 0;
	virtual void setLogTimeMaxInterval(const int& maxInterval_h) = 0;
	virtual void writeLogs(const char* logs) = 0;
	virtual void closeLogsFile() = 0;
	virtual ~LibLogsSystem(){}
};

extern LIB_LOGS_API LibLogsSystem* CreateLogesSystem(LogsType logsType = TIME_SHARE);

extern LIB_LOGS_API void DestroyLogsSystem(LibLogsSystem* logsSys);



LIB_LOGS_END
#endif





