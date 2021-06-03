// filename : main.c
// 参考：http://blog.sina.com.cn/s/blog_40ac9d43010179iq.html

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetPidByCmdline(const char *cmd)
{
	DIR *dir;
	struct dirent *ptr;
	FILE *fp;
	//大小随意，能装下cmdline文件的路径即可, 但是最好超过270，否则编译第31行会有警告。
	char filepath[270];
	 //大小随意，能装下要识别的命令行文本即可
	char filetext[256];

	dir = opendir("/proc"); //打开路径
	if (NULL != dir) {
		//循环读取路径下的每一个文件/文件夹
		while ((ptr = readdir(dir)) != NULL) {
			//如果读取到的是"."或者".."则跳过
			if ((strcmp(ptr->d_name, ".") == 0) ||
			    (strcmp(ptr->d_name, "..") == 0))
				continue;
			//读取到的不是文件夹名字也跳过
			if (DT_DIR != ptr->d_type)
				continue;
			//生成要读取的文件的路径
			sprintf(filepath, "/proc/%s/cmdline", ptr->d_name);
			fp = fopen(filepath, "r"); //打开文件

			if (NULL != fp) {
				fread(filetext, 1, 50, fp); //读取文件
				//给读出的内容加上字符串结束符
				filetext[255] = '\0';
				//如果文件内容满足要求则打印路径的名字（即进程的PID）
				if (filetext == strstr(filetext, cmd)) {
					int pid = atoi(ptr->d_name);
					printf("cmd:\'%s\', PID:%d\n", cmd, pid);
					return pid;
				}
				fclose(fp);
			}
		}
	}
	printf("cmd:\'%s\', no such process.\n", cmd);
	return 0;
}

void main()
{
	char cmd[] = "./test";
	int pid = GetPidByCmdline(cmd);
}