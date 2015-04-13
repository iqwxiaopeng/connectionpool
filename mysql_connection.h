#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H
#include <stdio.h>

class MySQLConn
{
public:
	MySQLConn() {};
	~MySQLConn() {};
	void Print() { printf("hello\n"); }
};
#endif