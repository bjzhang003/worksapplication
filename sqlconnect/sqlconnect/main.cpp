/*************************************************************************
    > File Name: main.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月20日 星期四 15时23分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include"mydb.h"
using namespace std;
int main(int argc,char **argv)
{
	CMyDB my=CMyDB();
	my.initDB("localhost","root","zhangbaojia","works");
	my.executeSQL("create table dealRecord(Code VARCHAR(20),Name VARCHAR(20),price DOUBLE,Count INT,Expence DOUBLE,Discount DOUBLE,totalcount INT,totalprice DOUBLE,discountprice DOUBLE,payment DOUBLE,changeData DOUBLE,casher VARCHAR(20),POS VARCHAR(20),LOGDATE DATE);");

	cout<<"111"<<endl;
	/*
	for(int i=0;i<10;i++)
	{
		string Name;
		for(int j=0;j<10;j++)
		{
			Name.push_back('a'+rand()%26);
		}
		
		stringstream IO;
		IO.clear();
		int TempId=rand();
		string ID;
		IO<<TempId;
		IO>>ID;

		IO.clear();
		int TempSex=rand()%2;
		string Sex;
		if(1==(TempSex&0x1))
		{
			Sex="Man";
		}
		else
		{
			Sex="Woman";
		}

		string InsertData="";
		InsertData=InsertData+"insert into Number(name,std_id,stu_sex) values("+"'"+Name+"'"+","+ID+","+"'"+Sex+"'"+");";

		cout<<InsertData<<endl;
		my.executeSQL(InsertData.c_str());
	}

	*/
	//my.executeSQL("select * from Number;");
	//my.executeSQL("drop table Number;");
	return 0;
}
