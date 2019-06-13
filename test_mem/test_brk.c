/*************************************************************************
    > File Name: test_brk.c
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年05月17日 星期五 11时48分13秒
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>

int main()
{
//	int *p = sbrk(0);
//	printf("p:\t%p\n",p);
//
//	sbrk(1024*1024);
//
//	p = sbrk(0);
//	printf("p:\t%p\n",p);
//
//	sbrk(-1024*1024);
//
//	p = sbrk(0);
//	printf("p:\t%p\n",p);

	void *tret;
	char *pmem;

	tret = sbrk(0);
	if(tret != (void*)-1)
		printf("heap start:\t%p\n",tret);

	pmem = (char*)malloc(1);
	printf("pmem:\t%p\t%d\t%p\n",pmem,*((int*)(pmem-8)),*((int*)(pmem-16)));
	tret = sbrk(0);
	printf("heap start:\t%p\n",tret);
	

	pmem = (char*)malloc(24);
	printf("pmem:\t%p\t%d\t%p\n",pmem,*((int*)(pmem-8)),*((int*)(pmem-16)));
	tret = sbrk(0);
	printf("heap start:\t%p\n",tret);

	pmem = (char*)malloc(1);
	printf("pmem:\t%p\t%d\t%p\n",pmem,*((int*)(pmem-8)),*((int*)(pmem-16)));
	tret = sbrk(0);
	printf("heap start:\t%p\n",tret);

	tret = sbrk(0);
	if(tret != (void*)-1)
		printf("实际上调用brk分配了:\t%p字节\n",(char*)tret);

	return 0;
}
