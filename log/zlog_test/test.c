#include <stdio.h>
#include "zlog.h"

int main(int argc, char **argv)
{
	int rc;
	zlog_category_t *zc;
	char hex_buf[32];

	rc = zlog_init("../zlog/zlog.conf");
	if (rc) {
		printf("EEROR: zlog init failed\n");
		return -1;
	}

	zc = zlog_get_category("my_cat");
	if (!zc) {
		printf("EEROR: zlog get cat fail\n");
		zlog_fini();
		return -2;
	}

	zlog_debug(zc, "hello, zlog - debug");
	zlog_info(zc, "hello, zlog - info");
	zlog_notice(zc, "hello, zlog - notice");
	zlog_warn(zc, "hello, zlog - warn");
	zlog_error(zc, "hello, zlog - error");
	zlog_fatal(zc, "hello, zlog - fatal");

	for (int i = 0; i < sizeof(hex_buf); i++) {
		hex_buf[i] = i;
	}
	hzlog_debug(zc, hex_buf, sizeof(hex_buf));

	zlog_fini();

	return 0;
}