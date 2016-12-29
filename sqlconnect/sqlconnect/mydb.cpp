/*************************************************************************
    > File Name: mydb.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: 2016年10月20日 星期四 14时59分50秒
 ************************************************************************/

#include"mydb.h"
CMyDB::CMyDB()
{
	//初始化连接数据库变量
	connection=mysql_init(NULL);
	if(connection==NULL)
	{
		perror("mysql_init");
		exit(1);
	}
}

CMyDB::~CMyDB()
{
	//关闭初始化数据库变量
	if(connection!=NULL)
	{
		mysql_close(connection);
	}
}

//初始化数据库 数据库连接
bool CMyDB::initDB(string server_host,string user,string password,string db_name)
{
	//运用mysql_real_connect函数是实现数据库的连接
	connection=mysql_real_connect(connection,server_host.c_str(),user.c_str(),password.c_str(),db_name.c_str(),0,NULL,0);
	if(connection==NULL)
	{
		perror("mysql_real_connect");
		exit(1);
	}
	return true;
}

//执行SQL语句
bool CMyDB::executeSQL(string sql_str)
{
	//查询编码设定
	if(mysql_query(connection,"set names utf8"))
	{
		fprintf(stderr,"%d:%s\n",mysql_errno(connection),mysql_error(connection));
	}
	int t=mysql_query(connection,sql_str.c_str());
	if(t)
	{
		//fprintf("Error making query:%s\n",mysql_error(connection));
		exit(1);
	}
	else
	{
		//初始化逐行的结果集检索
		MYSQL_RES* res=mysql_store_result(connection);
		if(res)
		{
			//mysql_field_count(connection) 返回作用在连接上的最近查询的列数
			//cout<<"mysql_num_rows = "<<mysql_num_rows(res)<<endl;
			//for(int i=0;i<mysql_field_count(connection);i++)
			for(int i=0;i<mysql_num_rows(res);i++)
			{
				//cout<<"i = "<<i<<endl;
				//检索一个集过集合的下一行
				row=mysql_fetch_row(res);
				if(row<=0)
				{
					break;
				}
				//mysql_num_fields(res)  函数返回结果集中字段的数据
				for(int r=0;r<mysql_num_fields(res);r++)
				{
					printf("%s\t",row[r]);
				}
				printf("\n");
			}
		}
		//释放结果集使用的内存
		mysql_free_result(res);
	}
	return true;
}

//表的创建
bool CMyDB::create_table(string table_str_sql)
{
	int t=mysql_query(connection,table_str_sql.c_str());
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(connection));
		exit(1);
	}
	return true;
}
