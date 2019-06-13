/*************************************************************************
    > File Name: openSameFile2.c
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年05月18日 星期六 15时15分35秒
 ************************************************************************/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int fd = open("./hz.txt",O_RDWR | O_APPEND);
	while(1){
		sleep(1);
		write(fd,"b",1);
	}
	close(fd);
	return 0;
}
