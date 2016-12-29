/*************************************************************************
    > File Name: Date.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 03:02:10 AM EDT
 ************************************************************************/

#include<iostream>
#include<time.h>
#include<sstream>
using namespace std;

int main()
{
	time_t now;
	struct tm *tm_now;
	char * datetime;

	time(&now);
	tm_now=localtime(&now);

	datetime=asctime(tm_now);

	string result=datetime;
	cout<<result<<endl;
	return 0;
}
