#include <stdio.h>
#include "zlog.h"

#define VACC_LOG(format, ...) printf(format, ##__VA_ARGS__);

#define VACC_LOG2(format, ...)                                                 \
	zlog_category_t *c = zlog_get_category("my_cat");                      \
	if (c) {                                                               \
		zlog_info(c, ##__VA_ARGS__);                                   \
	}

int main(int argc, char **argv)
{
	int rc;
	zlog_category_t *c;
	rc = zlog_init("test_hello.conf"); //指定配置文件路径

	if (rc) {
		printf("init failed\n");
		return -1;
	}

	c = zlog_get_category("my_cat");
	// c = zlog_get_category("vastai_runtime_mem");

	if (!c) {
		printf("get cat fail\n");
		zlog_fini(); //释放zlog
		return -2;
	}
	zlog_info(c, "info, zlog");
	zlog_debug(c, "debug, zlog");

	// printf("%s\n", "printf: hello, zlog");
	// VACC_LOG("%s\n", "VACC_LOG: hello, zlog");
	// VACC_LOG2("%s", "VACC_LOG2: hello, zlog1");
	// VACC_LOG2("%s", "VACC_LOG2: hello, zlog2");
	// VACC_LOG2("%s", "VACC_LOG2: hello, zlog3");
	zlog_fini();
	return 0;
}
