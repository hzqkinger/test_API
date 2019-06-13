/*************************************************************************
    > File Name: test.cpp
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年06月06日 星期四 00时49分45秒
 ************************************************************************/

#include<iostream>
#include"json/json.h"

int main()
{
	Json::Value tmp;
	tmp["name"] = "hzq";
	tmp["school"] = "sust";
	std::cout << tmp << std::endl;
	return 0;
}
