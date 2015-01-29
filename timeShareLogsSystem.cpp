#include <stdlib.h>
#include <iostream>
#include "timeShareLogsSystem.h"
#include "insideAPI.h"
#include "libLogsMacro.h"

LIB_LOGS_BEGIN

TimeShareLogsSystem::TimeShareLogsSystem()
: mSaveDir("")
, mConditionFunc(nullptr)
{
	return;
}

TimeShareLogsSystem::~TimeShareLogsSystem()
{
	std::cout << "the TimeShareLogsSystem class destruct function is run ! " << std::endl;
	closeLogsFile();
	return;
}

void TimeShareLogsSystem::setSaveDir(const char* logsFileDir)
{
	if (logsFileDir)
	{
		if(!CreateFileDirectory(logsFileDir))
			std::cout << "Don't create file directory! " << std::endl;
		mSaveDir = std::move(std::string(logsFileDir));
	}
	return;
}

void TimeShareLogsSystem::setCreateNewFileConditionParam(CreateNewFileCondition condFunc)
{
	mConditionFunc = condFunc;
	return;
}

void TimeShareLogsSystem::writeLogs(const char* logs)
{
	if (!mFile.is_open())
	{
		if (!openSaveFile())
			return;
	}

	time_t lt = time(nullptr);
	tm* ptm = new tm;
	localtime_s(ptm, &lt);

	char szBuffer[64] = {0};
	strftime(szBuffer, 64, "|<< %Y-%m-%d %H:%M:%S >>| ", ptm);
	DELETE_POINT(ptm);

	std::string strLogs = szBuffer;
	strLogs.append(logs);
	strLogs.append(1, '\n');

	// write logs
	mFile << strLogs;
	mFile.flush();

	//the close condition
	if(isCloseLogsFile())
	{
		closeLogsFile();
	}
	return;
}

void TimeShareLogsSystem::closeLogsFile()
{
	if (mFile.is_open())
	{
		mFile.close();
	}
	return;
}

bool TimeShareLogsSystem::openSaveFile()
{
	bool res = true;
	time_t lt = time(NULL);
	tm* ptm = new tm;
	char szBuffer[64] = {0};
	localtime_s(ptm, &lt);
	strftime(szBuffer, 64, "%Y%m%d", ptm);

	std::string filePath = mSaveDir;
	filePath.append(1,LIB_LOGS_SEPARATORY);
	filePath.append(szBuffer);
	
	if(!CreateFileDirectory(filePath.c_str()))
		std::cout << "Don't create file directory! " << std::endl;

	memset(szBuffer, 0, sizeof(char) * 64);
	strftime(szBuffer, 64, "%Y%m%d_%H%M%S.txt", ptm);
	DELETE_POINT(ptm);

	filePath.append(1, LIB_LOGS_SEPARATORY);
	filePath.append(szBuffer);

	if (!mFile.is_open())
	{
		mFile.open(filePath,  std::ios::app | std::ios::out);
		if (!mFile.is_open())
		{
			std::cout << "The save file open fail !" << std::endl;
			res = false;
		}
		else
		{
			mCreateClock = clock();
		}
	}
	return res;
}

bool TimeShareLogsSystem::isCloseLogsFile()
{
	mCloseClock = clock();
	return (mFile.is_open() && (mFile.tellp() > (LIB_LOGS_MAX_FILE_SIZE * 3000) || (mCloseClock - mCreateClock) > LIB_LOGS_MAX_CLOCK_INTERVAL));
}

LIB_LOGS_END
