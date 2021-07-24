
#include <stdlib.h>
#include <stdio.h>>

/**********************************************
* LOG DEFINE *
**********************************************/
enum vacc_log_level { OFF = 0, FATAL, ERROR, WARN, INFO, DEBUG, TRACE, ALL };

#define VACC_LOG_LEVEL ALL

#define VACC_LOG(level, format, ...)                                           \
	if (VACC_LOG_LEVEL >= level) {                                         \
		printf("[%s] [func:%s,file:%s,line:%d] " format "\n", #level,  \
		       __func__, __FILE__, __LINE__, ##__VA_ARGS__);           \
	}

#define LOG_OFF(format, ...) VACC_LOG(OFF, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) VACC_LOG(FATAL, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) VACC_LOG(ERROR, format, ##__VA_ARGS__)
#define LOG_WARN(format, ...) VACC_LOG(WARN, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...) VACC_LOG(INFO, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...) VACC_LOG(DEBUG, format, ##__VA_ARGS__)
#define LOG_TRACE(format, ...) VACC_LOG(TRACE, format, ##__VA_ARGS__)
#define LOG_ALL(format, ...) VACC_LOG(ALL, format, ##__VA_ARGS__)

void test_log()
{
	LOG_OFF("LOG_OFF");
	LOG_FATAL("LOG_FATAL");
	LOG_ERROR("LOG_ERROR");
	LOG_WARN("LOG_WARN");
	LOG_INFO("LOG_INFO");
	LOG_DEBUG("LOG_DEBUG");
	LOG_TRACE("LOG_TRACE");
	LOG_ALL("LOG_ALL");
}

int main(){
  test_log();
}