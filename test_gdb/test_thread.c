#include<iostream>
using std::cout;
using std::endl;
#include<pthread.h>
#include<unistd.h>

void *run_l(void *arg)
{
	//pthread_detach(pthread_self());
	int index = 0;
	while(1){
		cout << "l = " << index++ << endl;
		sleep(1);
	}
}
void *run_m(void *arg)
{
	//pthread_detach(pthread_self());
	int index = 0;
	while(1){
		cout << "m = " << index++ <<  endl;
		sleep(1);
	}
}
int main()
{
	pthread_t l,m,n;
	pthread_create(&l,NULL,run_l,NULL);
	pthread_create(&m,NULL,run_m,NULL);

	cout << "i am main thread" << endl;

	pthread_join(l,NULL);
	pthread_join(m,NULL);
	return 0;
}
