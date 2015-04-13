#ifndef CONNECTION_POOL_H
#define CONNECTION_POOL_H
#include <memory>
#include <list>
#include <mutex.h>
#include <mysql_connection.h>
#include <nocopyable.h>
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<MySQLConn> Connection;
typedef std::list<Connection> ConnectionList;
class ConnectionPool:NonCopyable
{
public:

public:
	ConnectionPool() {};
	~ConnectionPool() {};
	Connection GetConnection();
private:
	const static int HighWaterMark = 1024;
private:
	ConnectionList list_;
	MutexLock lock_;
};
#endif