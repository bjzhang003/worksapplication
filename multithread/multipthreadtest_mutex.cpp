/*************************************************************************
    > File Name: multipthreadtest_mutex.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月25日 星期二 10时32分25秒
 ************************************************************************/

#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

int sum=0;
pthread_mutex_t sum_mutex;

void * say_hello(void * args)
{
	cout<<"hello in thread "<<*((int *)args)<<endl;

	pthread_mutex_lock(&sum_mutex);
	cout<<"before sum is "<<sum<<" in thread "<<*((int *)args)<<endl;
	sum+=*((int *)args);
	cout<<"after sum is "<<sum<<" in thread "<<*((int *)args)<<endl;
	pthread_mutex_unlock(&sum_mutex);
	pthread_exit(0);
}

int main()
{
	pthread_t tids[NUM_THREADS];
	int index[NUM_THREADS];

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&sum_mutex,NULL);

	for(int i=0;i<NUM_THREADS;i++)
	{
		index[i]=i;
		int ret = pthread_create(&tids[i],&attr,say_hello,(void *)&(index[i]));
		if(0!=ret)
		{
			cout<<"pthread_create error:error_code = "<<ret<<endl;
		}
	}

	pthread_attr_destroy(&attr);
	void *status;
	for(int i=0;i<NUM_THREADS;i++)
	{
		int ret = pthread_join(tids[i],&status);
		if(0!=ret)
		{
			cout<<"pthread_join error:error_code = "<<ret<<endl;
		}
	}
	cout<<"finally sum is "<<sum<<endl;
	pthread_mutex_destroy(&sum_mutex);
	return 0;
}
