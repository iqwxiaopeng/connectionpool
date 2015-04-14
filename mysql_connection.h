#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H
#include <stdio.h>
#include <memory>
//typedef std::shared_ptr<MySQLRes> Result;
//typedef std::shared_ptr<MYSQL> MySQL;
class MySQLConn
{
public:
	MySQLConn() {};
	~MySQLConn() {};
	void Print() { printf("hello\n"); }
private:
	//Result result_;
	//MySQL mysql_;
};
#endif