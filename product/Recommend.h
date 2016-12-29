/*************************************************************************
    > File Name: Recommend.h
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 10:19:00 AM EDT
 ************************************************************************/

#ifndef _RECOMMEND_H_
#define _RECOMMEND_H_
#include<iostream>
#include<assert.h>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<sstream>
using namespace std;

class RecommendGood
{
	public:
		map<string,int> GoodAndCode;
		vector<vector<int> > history;

		void gethistory()
		{
			int count=0;
			ifstream in("./history.txt");
			assert(in);

			in.seekg(0,ios::beg);
			string Temp;
			if(in)
			{
				while(getline(in,Temp))
				{
					cout<<"HISTORY DATA IS "<<endl<<Temp<<endl;
					string TempHis;
					vector<string> Data;
					for(int i=0;i<Temp.size();i++)
					{
						if(Temp[i]==',')
						{
							Data.push_back(TempHis);
							TempHis.clear();
						}
						else
						{
							TempHis.push_back(Temp[i]);
						}
					}

					vector<int> oneline;
					stringstream IO;
					GoodAndCode.insert({Data[0],count++});
					for(int i=1;i<Data.size();i++)
					{
						IO.clear();
						int Thi;
						IO<<Data[i];
						IO>>Thi;
						oneline.push_back(Thi);
					}
					history.push_back(oneline);
				}
			}

			/*
			for(int i=0;i<history.size();i++)
			{
				for(int j=0;j<history[i].size();j++)
				{
					cout<<history[i][j]<<" ";
				}
				cout<<endl;
			}
			for(auto it=GoodAndCode.begin();it!=GoodAndCode.end();it++)
			{
				cout<<it->first<<"  -  "<<it->second<<endl;
			}
			*/
		}

		vector<string> RecommendGoodToPerson(vector<string> GoodNames)
		{
			vector<int> BuyGood;
			for(int i=0;i<GoodAndCode.size();i++)
			{
				BuyGood.push_back(0);
			}

			for(int i=0;i<GoodNames.size();i++)
			{
				if(GoodAndCode.find(GoodNames[i])!=GoodAndCode.end())
				{
					BuyGood[GoodAndCode.find(GoodNames[i])->second]=1;
				}
			}

			//calculate good
			double like=-1;
			vector<int> likeData;
			for(int col=0;col<GoodAndCode.size();col++)
			{
				//clculate cos data
				double mole=0;
				double buySum=0;
				double likeSum=0;
				vector<int> likeTemp;
				for(int row=0;row<history.size();row++)
				{
					mole=mole+history[row][col]*BuyGood[row];
					buySum=buySum+BuyGood[row];
					likeSum=likeSum+history[row][col];
					likeTemp.push_back(history[row][col]);
				}

				if(likeSum*buySum>0)
				{
					if(like<(mole/(likeSum*buySum)))
					{
						like=(mole/(likeSum*buySum));
						likeData=likeTemp;
					}
				}
			}

			vector<string> RecommendResult;
			for(int i=0;i<likeData.size();i++)
			{
				if(likeData[i]==1&&BuyGood[i]==0)
				{
					for(auto it=GoodAndCode.begin();it!=GoodAndCode.end();it++)
					{
						if(i==it->second)
						{
							RecommendResult.push_back(it->first);
							//cout<<it->first<<endl;
						}
					}
				}
			}
			if(RecommendResult.size()>3)
			{
				set<string> TempRe;
				while(TempRe.size()<3)
				{
					int ranTemp=rand()%RecommendResult.size();
					TempRe.insert(RecommendResult[ranTemp]);
				}
				RecommendResult.clear();
				for(auto it=TempRe.begin();it!=TempRe.end();it++)
				{
					RecommendResult.push_back(*it);
				}
			}
			if(RecommendResult.size()==0)
			{
				int ranTemp=rand()%GoodAndCode.size();
				auto it=GoodAndCode.begin();
				for(int i=0;i<=ranTemp;i++)
				{
					if(it!=GoodAndCode.end())
					{
						it++;
					}
				}
				if(it!=GoodAndCode.end())
				{
					RecommendResult.push_back(it->first);
				}
				else
				{
					RecommendResult.push_back(GoodAndCode.begin()->first);
				}
			}
			return RecommendResult;
		}

};

#endif

