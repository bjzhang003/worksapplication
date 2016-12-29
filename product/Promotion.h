/*************************************************************************
    > File Name: Promotion.h
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 03:53:51 AM EDT
 ************************************************************************/
#ifndef _PROMOTION_H_
#define _PROMOTION_H_
#include<iostream>
#include<assert.h>
#include<fstream>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;

class PromotionData
{
	public:
		void Promotion()
		{
			ifstream in("./promotion.txt");
			assert(in);
		
			in.seekg(0,ios::beg);
			string Temp;
			if(in)
			{
				while(getline(in,Temp))
				{
					cout<<"PROMOTION DATA IS "<<Temp<<endl;
					string TempGood;
					vector<string> One;
					for(int i=0;i<Temp.size();i++)
					{
						if(Temp[i]==',')
						{
							One.push_back(TempGood);
							TempGood.clear();

						}
						else
						{
							TempGood.push_back(Temp[i]);
						}
					}

					stringstream IO;
					IO.clear();
					double rate=0;
					IO<<TempGood;
					IO>>rate;

					ProMap.insert({{One[0],One[1]},rate});
				}
			}
			in.close();
		}

		map<pair<string,string>,double> ProMap;
};
#endif
