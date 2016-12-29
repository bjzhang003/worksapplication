/*************************************************************************
    > File Name: Test.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 03:54:11 AM EDT
 ************************************************************************/
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include"Recommend.h"
using namespace std;
int main()
{

	RecommendGood Test;
	Test.gethistory();
	vector<string> names ={"apple","orange"};
	vector<string> result = Test.RecommendGoodToPerson(names);

	cout<<"result is "<<endl;
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
