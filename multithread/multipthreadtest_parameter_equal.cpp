/*************************************************************************
    > File Name: multipthreadtest_parameter_equal.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月25日 星期二 10时08分06秒
 ************************************************************************/

#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

void * say_hello(void * args)
{
	cout<<"hello in thread "<<*((int *)args)<<endl;
}

int main()
{
	pthread_t tids[NUM_THREADS];
	int index[NUM_THREADS];

	for(int i=0;i<NUM_THREADS;i++)
	{
		index[i]=i;
		int ret = pthread_create(&tids[i],NULL,say_hello,(void*)&(index[i]));
		if(0!=ret)
		{
			cout<<"pthread_create error:error_code = "<<ret<<endl;
		}
	}
	for(int i=0;i<NUM_THREADS;i++)
		pthread_join(tids[i],NULL);
	return 0;
}
