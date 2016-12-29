/*************************************************************************
    > File Name: GenerateHistory.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Sat 29 Oct 2016 08:51:00 PM EDT
 ************************************************************************/

#include<iostream>
#include<assert.h>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<stdlib.h>
using namespace std;
const int sizeSample=100;

int main()
{

	ifstream in("./kinds.txt");
	ofstream fout;
	fout.open("history.txt",ios_base::out);


	assert(in);

	in.seekg(0,ios::beg);

	string Temp;
	if(in)
	{
		while(getline(in,Temp))
		{
			cout<<"KINDS OF GOODS ARE "<<Temp<<endl;
			string TempGood;

			stringstream IO;

			for(int i=0;i<Temp.size();i++)
			{
				if(Temp[i]==',')
				{
					if(!TempGood.empty())
					{
						string OutStr="";
						OutStr=OutStr+TempGood+",";
						string TempOut;
						for(int i=0;i<sizeSample;i++)
						{
							int ranBuy=rand()%2;
							IO.clear();
							IO<<ranBuy;
							IO>>TempOut;
							OutStr=OutStr+TempOut+",";
						}
						OutStr.push_back('\n');
						fout<<OutStr;
					}
					TempGood.clear();
				}
				else
				{
					TempGood.push_back(Temp[i]);
				}
			}

			if(!TempGood.empty())
			{
				string OutStr="";
				OutStr=OutStr+TempGood+",";
				string TempOut;
				for(int i=0;i<sizeSample;i++)
				{
					int ranBuy=rand()%2;
					IO.clear();
					IO<<ranBuy;
					IO>>TempOut;
					OutStr=OutStr+TempOut+",";
				}
				OutStr.push_back('\n');
				fout<<OutStr;
			}

		}
	}
	fout.close();

	return 0;
}



