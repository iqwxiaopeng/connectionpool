#include <connection_pool.h>
#include <boost/bind.hpp>
#include <iostream>
using namespace std;
using namespace boost;
void echo()
{
	cout << "hello world" << endl;
}
int main()
{
    ConnectionPool pool;
    pool.GetConnection();
	pool.SetHighWaterMarkCallback(bind(&echo));
    return 0;
}
