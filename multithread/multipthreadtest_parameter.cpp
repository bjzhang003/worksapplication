/*************************************************************************
    > File Name: multipthreadtest_parameter.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月25日 星期二 09时58分54秒
 ************************************************************************/

#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

void* say_hello(void * args)
{
	int i=*((int*) args);
	cout<<"hello in "<<i<<endl;
}

int main()
{
	pthread_t tids[NUM_THREADS];
	cout<<"hello in main ..."<<endl;
	for(int i=0;i<NUM_THREADS;i++)
	{
		int ret=pthread_create(&tids[i],NULL,say_hello,(void*)&i);
		cout<<"Current pthread id ="<<tids[i]<<endl;
		if(0!=ret)
		{
			cout<<"pthread_create error:error_code ="<<ret<<endl;
		}
	}
	return 0;
}
