/*************************************************************************
    > File Name: field_test.cpp
    > Author: bjzhang03
    > Mail: bjzhang1991@gmail.com
    > Created Time: 2017年01月09日 星期一 15时20分34秒
 ************************************************************************/

#include<iostream>
#include<NTL/ZZ_pXFactoring.h>
#include<NTL/ZZ_pEX.h>
#include<NTL/GF2E.h>
#include<NTL/GF2EX.h>
#include<NTL/GF2EXFactoring.h>
#include<NTL/vector.h>
using namespace std;
using namespace NTL;

int main()
{
	ZZ x;
	GenPrime(x,128);

	ZZ_p::init(ZZ(97));
	cout<<"ZZ_p::modulus() = "<<ZZ_p::modulus()<<endl;
	cout<<"ZZ_p::ModulusSize = "<<ZZ_p::ModulusSize()<<endl;
	
	ZZ_p ZZPData;
	conv(ZZPData,x);
	cout<<"ZZPData = "<<ZZPData<<endl;
	random(ZZPData);
	cout<<"random ZZ_p  = "<<ZZPData<<endl;

	vec_ZZ_p VecZZP;
	VecZZP.SetLength(3,ZZPData);
	random(ZZPData);
	VecZZP[0]=ZZPData;
	cout<<"VecZZP = "<<VecZZP<<endl;

	return 0;
}

