/************************************************************************/
/* 设计一个时间和文件大小为新建日志文件。                                                              */
/************************************************************************/
#ifndef TIME_SHARE_LOGS_SYSTEM_H
#define TIME_SHARE_LOGS_SYSTEM_H
#include <fstream>
#include <time.h>
#include <string>
#include "libLogs.h"

LIB_LOGS_BEGIN
/**
 * 日志文件管理
 */
class TimeShareLogsSystem : public LibLogsSystem
{
public:
	TimeShareLogsSystem();
	~TimeShareLogsSystem();

	virtual void setSaveDir(const char* logsFileDir) override;
	virtual void setCreateNewFileConditionParam(CreateNewFileCondition condFunc) override;
	virtual void writeLogs(const char* logs) override;
	virtual void closeLogsFile() override;

protected:
	bool openSaveFile();
	bool isCloseLogsFile();
protected:
	std::string mSaveDir;
	std::ofstream mFile;
    clock_t mCreateClock;
	clock_t mCloseClock;
	CreateNewFileCondition mConditionFunc;
};

LIB_LOGS_END

#endif
