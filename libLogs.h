/************************************************************************/
/* libLogs用于产生一个可以扩展和用户定制的日志操作库函数。                                */
/************************************************************************/

#ifndef LIB_LOGS_H
#define LIB_LOGS_H

#include "platform.h"

LIB_LOGS_BEGIN


	typedef bool (*CreateNewFileCondition)();

/************************************************************************/
/* 设置一个日志系统接口结构，这是一个抽象接口类                                                  */
/************************************************************************/
 LIB_LOGS_INTERFACE LIB_LOGS_API LibLogsSystem
{
	virtual void setSaveDir(const char* logsFileDir) = 0;
	virtual void setCreateNewFileConditionParam(CreateNewFileCondition condFunc) = 0;
	virtual void writeLogs(const char* logs) = 0;
	virtual void closeLogsFile() = 0;
	virtual ~LibLogsSystem(){}
};


 enum LogsType
 {
	 TIME_SHARE = 0

 };

 /************************************************************************/
 /* 创建一个LibLogsSystem接口的实例。注意这个实例是从API中在堆栈中申请。     */
 /************************************************************************/
extern LIB_LOGS_API LibLogsSystem* CreateLogesSystem(LogsType logsType = TIME_SHARE);


/************************************************************************/
/* 销毁一个由CreateLogesSystem创建的实例。内部将会将文件进行关闭操作            */
/************************************************************************/
extern LIB_LOGS_API void DestroyLogsSystem(LibLogsSystem* logsSys);



LIB_LOGS_END
#endif





