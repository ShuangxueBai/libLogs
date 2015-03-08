/************************************************************************/
/* A logs system that set max size of file and max interval of timer.   */
/************************************************************************/
#ifndef TIME_SHARE_LOGS_SYSTEM_H
#define TIME_SHARE_LOGS_SYSTEM_H
#include <fstream>
#include <time.h>
#include <string>
#include "libLogs.h"

LIB_LOGS_BEGIN
/**
 * TimeShareLogsSystem
 */
class TimeShareLogsSystem : public LibLogsSystem
{
public:
	TimeShareLogsSystem();
	~TimeShareLogsSystem();

	virtual void setSaveDir(const char* logsFileDir) override;
	virtual void setLogFileMaxSize(const int& maxSize_kb) override;
	virtual void setLogTimeMaxInterval(const int& maxInterval_h) override;
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
	int mMaxSize;
	int mMaxInterval;
};

LIB_LOGS_END

#endif
