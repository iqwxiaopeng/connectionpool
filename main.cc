//#include <connection_pool.h>
#include <memory>
#include <iostream>
#include <mysql_connection.h>
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
//     ConnectionPool pool;
//     pool.GetConnection();
// 	pool.SetHighWaterMarkCallback(bind(&echo));
	typedef std::shared_ptr<MySQLConn> Connection;
	Connection conn(new MySQLConn());
	cout << conn->Connect("192.168.0.129", "SCS", "123456", 2000) << endl;
	ResultSet set = conn->ExecuteQuery("show databases");
	cout << set->GetString() << endl;
    return 0;
}
