/*************************************************************************
    > File Name: mydb.h
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月20日 星期四 14时53分57秒
 ************************************************************************/

#ifndef _MY_DB_H

#include<mysql/mysql.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

class CMyDB
{
	public:
		CMyDB();
		bool initDB(string server_host,string user,string password,string db_name);
		bool executeSQL(string sql_str);
		bool create_table(string table_str_sql);
		~CMyDB();
	private:
		MYSQL *connection;
		MYSQL_RES *res;
		MYSQL_ROW row;
};
#endif
