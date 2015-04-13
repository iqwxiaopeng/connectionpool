#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H
#include <stdio.h>
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<MySQLRes> Result;
typedef boost::shared_ptr<MYSQL> MySQL;
class MySQLConn
{
public:
	MySQLConn() {};
	~MySQLConn() {};
	void Print() { printf("hello\n"); }
private:
	Result result_;
	MySQL mysql_;
};
#endif