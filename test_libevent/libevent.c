/*************************************************************************
    > File Name: libevent.c
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年06月04日 星期二 22时22分59秒
 ************************************************************************/

#include<stdio.h>
#include<event.h>

int main()
{
	//struct event_base * base = event_init();
	struct event_base * base = event_base_new();
	const char *x = event_base_get_method(base);//查看用了哪个IO多路复用模型	
	printf("method:\t%s\n",x);
	
	event_base_dispatch(base);
	event_base_free(base);
	return 0;
}

