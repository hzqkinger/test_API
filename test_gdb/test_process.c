#include<unistd.h>
#include<stdlib.h>
#include<iostream>
using std::cout;
using std::endl;
using std::cerr;
int main()
{
	pid_t pid;
	if((pid = fork()) < 0){
		cerr << "fork" << endl;
		exit(1);
	}
	else if(pid == 0){
		int index = 0;
		while(1){
			cout << "in child : " << index++ << endl;
			usleep(1000000);
		}
	}
	else{
		int index = 0;
		while(1){
			cout << "in parent : " << index++ << endl;
			usleep(1000000);
		}
	}

	return 0;
}
