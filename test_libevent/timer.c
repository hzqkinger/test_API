/*************************************************************************
    > File Name: timer.c
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年06月12日 星期三 12时50分08秒
 ************************************************************************/
//vim          vs2013
//u      <===> ctrl+z   撤销上一步的操作
//ctrl+R <===> ctrl+y   恢复上一步被撤销的操作
//
//流行的文本编辑器通常都有前进和后退功能，可以在文件中曾经浏览过的位置之间来回移动。
//在 vim 中使用 Ctrl-O 执行后退，使用 Ctrl-I 执行前进


#include<stdio.h>
#include<event.h>

struct event ev;
struct timeval tv;

void time_cb(int fd,short event,void *arg)
{
	printf("timer wakeup\n");
	//event_add(&ev,&tv);//reschedule timer
}
int main()
{
	struct event_base *base = event_init();
	// 1) 首先用event_init()函数初始化libevent库，并保存返回的指针。
	// (在用libevent库之前必须先调用这个函数)
	tv.tv_sec = 3;
	tv.tv_usec = 0;

	evtimer_set(&ev,time_cb,NULL);
	// 2) 该函数等价于 event_set(&ev,-1,0,time_cb,NULL);
	// void event_set(struct event *ev,int fd,short event, \
	//                    void(*cb)(int,short,void*),void *arg);
	// ev    执行要初始化的event对象
	// fd    该event绑定的"句柄"，对于信号事件，它就是关注的信号
	// event 在该fd上关注的事件类型，它可以是:EV_READ,EV_WRITE,EV_SIGNAL
	// time_cb 函数指针
	// arg 传递给cb函数指针的参数
	
	event_add(&ev,&tv);
	// 3) 正式添加事件，这一步相当于调用Reactor::register_handler()函数注册事件
	event_base_dispatch(base);
	// 4) 程序进入死循环，等待就绪事件并执行事件处理

	return 0;
}
