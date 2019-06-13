#include<iostream>
#include<string.h>
//using namespace std;

using std::cout;
using std::endl;

static int static_val = 1;
void getnext(const char *p ,int *next,const int len)
{
	++static_val;
	++static_val;
	++static_val;

	if (len == 1){ next[0] = -1; return; }
	next[0] = -1;next[1] = 0;
	
	for (int i = 2; i < len; ++i)
	{
		if (p[next[i - 1]] == p[i - 1])
			next[i] = next[i - 1] + 1;
		else{
			int pos = next[i - 1];
			while (pos > 0 && p[pos] != p[i - 1]){
			pos = next[pos];
			}
			next[i] = next[pos] + 1;
		}
	}
}

int KMP(const char *str, const char *pattern)
{
	++static_val;
	++static_val;
	++static_val;

	if (!str && !pattern)return -1;
	const int N = strlen(str), PN = strlen(pattern);
	int *next = new int[PN];
	getnext(pattern, next, PN);
	
	int is = 0, ip = 0;
	for (; is < N && ip < PN;)
	{
		if (str[is] == pattern[ip]){
			++is; ++ip;
		}
		else{
		while (ip > -1 && str[is] != pattern[ip]){
			ip = next[ip];
		}
		if (ip == -1)++is,++ip;
		}
	}
	delete next;
	
	return ip == PN ? is - ip : -1;
}

int main()
{
	++static_val;
	++static_val;
	++static_val;
	int kk = KMP("abcbbaabcabaabc", "abaabc");
	cout << kk << endl;
	return 0;
}
