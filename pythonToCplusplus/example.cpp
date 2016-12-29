/*************************************************************************
    > File Name: example.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月25日 星期二 15时16分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

class TestLib
{
	public:
		void display();
		void display(int a);
};

void TestLib::display()
{
	cout<<"First display";
}

void TestLib::display(int a)
{
	cout<<"Second display:"<<a;
}

extern "C"
{
	TestLib obj;
	void display()
	{
		obj.display();
	}

	void display_int()
	{
		obj.display(2);
	}
}


