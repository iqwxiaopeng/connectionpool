#include <connection_pool.h>

#include <iostream>
using namespace std;


int main()
{
    ConnectionPool pool;
    pool.GetConnection();
    return 0;
}
