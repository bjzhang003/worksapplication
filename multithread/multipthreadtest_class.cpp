/*************************************************************************
    > File Name: multipthreadtest_class.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月25日 星期二 09时50分23秒
 ************************************************************************/

#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

class Hello
{
	public:
		static void * say_hello(void * args)
		{
			cout<<"hello..."<<endl;
		}
};

int main()
{
	pthread_t tids[NUM_THREADS];
	for(int i=0;i<NUM_THREADS;i++)
	{
		int ret=pthread_create(&tids[i],NULL,Hello::say_hello,NULL);
		if(0!=ret)
		{
			cout<<"pthread_create error:error_code"<<ret<<endl;
		}
	}
	pthread_exit(NULL);
	return 0;
}

