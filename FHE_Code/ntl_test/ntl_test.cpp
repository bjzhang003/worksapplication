/*************************************************************************
    > File Name: ntl_test.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Thu 29 Dec 2016 03:11:07 AM EST
 ************************************************************************/

#include<iostream>
#include<NTL/ZZ.h>
using namespace std;
using namespace NTL;

int main()
{
	ZZ a,b,c;
	cin>>a;
	cin>>b;
	c=(a+1)*(b+1);
	cout<<c<<endl;
	return 0;
}
