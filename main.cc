//#include <connection_pool.h>
#include <memory>
#include <iostream>
#include <mysql_connection.h>
#include <stdio.h>
using namespace std;

void echo()
{
	cout << "hello world" << endl;
}
class Free
{
public:
	void operator()(char *ptr){ cout << "free char " << endl; }
};
class Alloc
{
public:
	void operator()(char *ptr){ cout << "Alloc char " << endl; }
};
char* init()
{
	cout << "new char()" << endl;
	return new char();
}
using namespace yang;
int main()
{
	typedef std::shared_ptr<MySQLConn> Connection;
	Connection conn(new MySQLConn());
	cout << conn->Connect("192.168.0.129", "SCS", "123456", 2000) << endl;
	ResultSet set = conn->ExecuteQuery("show databases");
	weak_ptr<MySQLRes> wp(set);
	printf("weak_ptr %d\n", set.use_count());
	cout << set->GetString(0) << endl;
    return 0;
}
