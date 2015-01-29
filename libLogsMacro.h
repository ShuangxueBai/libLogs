/************************************************************************/
/* 整理库中使用到的宏定义。                                                                                           */
/************************************************************************/

#ifndef  LIB_LOGS_MACRO_H
#define LIB_LOGS_MACRO_H


#define LIB_LOGS_MAX_PATH 260
#define LIB_LOGS_MAX_FILE_SIZE 1000 // 1KB
#define LIB_LOGS_MAX_CLOCK_INTERVAL 360000 // 1 hour

#define DELETE_POINT(x) do{ if(x) { delete (x); x = NULL; } }while (0)



#endif



