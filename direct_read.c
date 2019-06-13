/*************************************************************************
    > File Name: test_direct_read.c
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年05月21日 星期二 18时16分47秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int a = 1;
//	int fd = open("test.c",O_RDONLY);
	read(0,&a,sizeof(a));

	printf("%d\n",a);
	return 0;
}
