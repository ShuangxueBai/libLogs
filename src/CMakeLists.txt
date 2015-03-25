set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(LIB_SRC insideAPI.h libLogs.h libLogsMacro.h libPlatform.h timeShareLogsSystem.h insideAPI.cpp libLogs.cpp timeShareLogsSystem.cpp)
add_definitions("-DLIB_LOGS_EXPORTS")
add_library(libLogs SHARED ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

