/*************************************************************************
    > File Name: Test.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Thu 29 Dec 2016 02:35:13 AM EST
 ************************************************************************/

#include<iostream>
#include<gmpxx.h>
using namespace std;

int main()
{
	mpz_t a,b,c;
	mpz_init(a);
	mpz_init(b);
	mpz_init(c);
	gmp_scanf("%Zd%Zd",a,b);
	mpz_add(c,a,b);
	gmp_printf("%Zd\n",c);
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(c);
	return 0;
}
