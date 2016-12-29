/*************************************************************************
    > File Name: Pay.h
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 09:54:53 AM EDT
 ************************************************************************/
#ifndef _PAY_H_
#define _PAY_H_
#include<iostream>
#include<assert.h>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class PayAndCasher
{
	public:
		double pay;
		string casher;
		string pos;

		void payData()
		{
			ifstream in("./pay.txt");
			assert(in);

			in.seekg(0,ios::beg);
			if(in)
			{
				string Temp;
				getline(in,Temp);
				vector<string> Data;
				string TempStr;
				for(int i=0;i<Temp.size();i++)
				{
					if(Temp[i]==',')
					{
						Data.push_back(TempStr);
						TempStr.clear();
					}
					else
					{
						TempStr.push_back(Temp[i]);
					}
				}
				Data.push_back(TempStr);
				stringstream IO;
				IO.clear();
				IO<<Data[0];
				IO>>pay;
				casher=Data[1];
				pos=Data[2];
			}

		}
};
#endif
