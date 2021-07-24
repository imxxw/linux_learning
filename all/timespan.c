#include <sys/time.h>
#include <stdio.h>

typedef enum Time_Unit {
	tUSECOND = 0, //us
	tMSECOND,
	tSECOND,
	tMINUTE,
	tHOUR,
	tDAY,
	tMONTH,
	tYEAR,
} TimeUnit;

double GetTimeSpan(struct timeval tvBegin, struct timeval tvEnd, TimeUnit tu)
{
	double span = 0;
	//<1>.获得毫秒数:
	double span_us = 1000 * 1000 * (tvEnd.tv_sec - tvBegin.tv_sec) +
			 (tvEnd.tv_usec - tvBegin.tv_usec);
	switch (tu) {
	case tUSECOND:
		span = span_us;
		break;
	case tMSECOND:
		span = span_us / (1000.0);
		break;
	case tSECOND:
		span = span_us / (1000.0 * 1000);
		break;
	case tMINUTE:
		span = span_us / (1000.0 * 1000 * 60);
		break;
	case tHOUR:
		span = span_us / (1000.0 * 1000 * 60 * 60);
		break;
	case tDAY:
		span = span_us / (1000.0 * 1000 * 60 * 60 * 24);
		break;
	case tMONTH:
		span = span_us / (1000.0 * 1000 * 60 * 60 * 24 * 30);
		break;
	case tYEAR:
		span = span_us / (1000.0 * 1000 * 60 * 60 * 24 * 30 * 365);
		break;
	default:
		break;
	}
	return span;
}

int main()
{
	struct timeval tvBegin, tvEnd;
	gettimeofday(&tvBegin, NULL);

	sleep(2);

	//耗时函数执行...
	gettimeofday(&tvEnd, NULL);

	//<1>.获得毫秒数:
	double dDuration0 = GetTimeSpan(tvBegin, tvEnd, tUSECOND);
	printf("dDuration = %fus\n", dDuration0);

	//<1>.获得毫秒数:
	double dDuration1 = GetTimeSpan(tvBegin, tvEnd, tMSECOND);
	printf("dDuration = %fms\n", dDuration1);

	//<2>.获得秒数:
	double dDuration2 = GetTimeSpan(tvBegin, tvEnd, tSECOND);
	printf("dDuration = %fs\n", dDuration2);
}