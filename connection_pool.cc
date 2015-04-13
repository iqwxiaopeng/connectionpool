#include <connection_pool.h>


Connection ConnectionPool::GetConnection()
{
	{
		MutexLockGuard lock(lock_);
		list_.size();
		Connection conn(new MySQLConn());
		conn->Print();
		return conn;
	}

}