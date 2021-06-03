// filename : main.c
// 参考：http://blog.sina.com.cn/s/blog_40ac9d43010179iq.html

#include <stdio.h>
#include <string.h>

void GetPidByProcessName(const char* pname){
	//打开管道，执行shell 命令
	char pscmd[256];
	sprintf(pscmd, "ps -e | grep \'%s\' | awk \'{print $1}\'", pname);
	FILE *fp = popen(pscmd, "r");
	char buffer[10] = { 0 };
	while (NULL != fgets(buffer, 10, fp)) {
		//逐行读取执行结果并打印
		printf("PID:  %s", buffer);
	}
	//关闭返回的文件指针，注意不是用fclose噢
	pclose(fp);
}

void main()
{
	GetPidByProcessName("test");
}