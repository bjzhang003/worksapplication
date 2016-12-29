/*************************************************************************
    > File Name: Bought.h
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 07:35:32 AM EDT
 ************************************************************************/
#ifndef _BOUGHT_H_
#define _BOUGHT_H_
#include<iostream>
#include<assert.h>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<sstream>
#include"Promotion.h"
using namespace std;

struct goodBought{
	string code;
	string name;
	double price;
	int count;
	double promotion;
};

class BoughtData
{
	public:
		vector<goodBought> GoodsB;

		void BoughtDataInput()
		{
			ifstream in("./bought.txt");
			assert(in);

			in.seekg(0,ios::beg);
			string Temp;
			set<string> BData;
			if(in)
			{
				while(getline(in,Temp))
				{
					cout<<"BOUGHT GOODS ARE "<<Temp<<endl;
					string TempGood;
					vector<string> Data;
					for(int i=0;i<Temp.size();i++)
					{
						if(Temp[i]==',')
						{
							Data.push_back(TempGood);
							TempGood.clear();
						}
						else
						{
							TempGood.push_back(Temp[i]);
						}
					}
					Data.push_back(TempGood);

					goodBought TData;
					TData.code=Data[0];
					TData.name=Data[1];
					BData.insert(Data[1]);

					double priceData;
					stringstream IO;
					IO.clear();
					IO<<Data[2];
					IO>>priceData;
					TData.price=priceData;
					int countData;
					IO.clear();
					IO<<Data[3];
					IO>>countData;
					TData.count=countData;
					TData.promotion=1;
					GoodsB.push_back(TData);
				}
			}

			//calculate promotion
			PromotionData Promote;
			Promote.Promotion();
			for(auto it=Promote.ProMap.begin();it!=Promote.ProMap.end();it++)
			{
				if(BData.find(it->first.first)!=BData.end()&&BData.find(it->first.second)!=BData.end())
				{
					for(int i=0;i<GoodsB.size();i++)
					{
						if(GoodsB[i].name==it->first.first||GoodsB[i].name==it->first.second)
						{
							GoodsB[i].promotion=it->second;
						}
					}
				}
			}

			/*
			for(int i=0;i<GoodsB.size();i++)
			{
				cout<<GoodsB[i].code<<"--"<<GoodsB[i].name<<"--"<<GoodsB[i].price<<"--"<<GoodsB[i].count<<"--"<<GoodsB[i].promotion<<endl;
			}
			*/
		}
};
#endif
