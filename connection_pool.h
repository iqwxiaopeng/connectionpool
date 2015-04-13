#ifndef CONNECTION_POOL_H
#define CONNECTION_POOL_H
#include <memory>
#include <list>
#include <mutex.h>
#include <mysql_connection.h>
#include <nocopyable.h>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

typedef boost::shared_ptr<MySQLConn> Connection;
typedef std::list<Connection> ConnectionList;
typedef boost::function<void()> HighWaterMarkCallback;

class ConnectionPool:NonCopyable
{
public:
	ConnectionPool() {};
	~ConnectionPool() {};
	Connection GetConnection();
	void SetHighWaterMarkCallback(const HighWaterMarkCallback &cb){
		highWaterMarkCallback_ = cb; cb();
	}
	int ReleaseConnection(const Connection &conn){};
private:
	const static int HighWaterMark = 1024;
private:
	ConnectionList list_;
	MutexLock lock_;
	HighWaterMarkCallback highWaterMarkCallback_;
};
#endif