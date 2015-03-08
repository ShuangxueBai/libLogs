#include "libLogs.h"
#include "timeShareLogsSystem.h"


LIB_LOGS_BEGIN


LibLogsSystem* CreateLogesSystem(LogsType logsType)
{
	LibLogsSystem* pRes = NULL;
	switch (logsType)
	{
	case LibLogs::TIME_SHARE:
		pRes = new TimeShareLogsSystem;
		break;
	default:
		break;
	}
	return pRes;
}

void DestroyLogsSystem(LibLogsSystem* logsSys)
{
	if (logsSys)
	{
		logsSys->closeLogsFile();
		delete logsSys;
	}
	return;
}

LIB_LOGS_END







