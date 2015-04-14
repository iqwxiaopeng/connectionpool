#include <mysql_connection.h>
#include <string.h>
#include <memory>
namespace yang
{
	using namespace std;
	int MySQLConn::Connect(const char *host, const char *user, const char *pwd, int port, const char *db)
	{
		mysql_options(mysql_.get(), MYSQL_OPT_COMPRESS, NULL);
		if (mysql_real_connect(mysql_.get(), host, user,
			pwd, db, port, NULL, 0) == NULL) return -1;
		connecting_ = true;
		return 0;
	}

	int MySQLConn::Execute(const char *sql)
	{
		int res = mysql_query(mysql_.get(), sql);
		if (res != 0) return mysql_errno(mysql_.get());
		return 0;
	}

	ResultSet MySQLConn::ExecuteQuery(const char *sql)
	{
		int res = mysql_real_query(mysql_.get(), sql, strlen(sql));

		if (res != 0) { result_.reset(); }

		MYSQL_RES *result = mysql_store_result(mysql_.get());
		if (result == NULL) { result_.reset(); }

		result_ = make_shared<MySQLRes>(result);
		return result_;
	}

	const char* MySQLConn::GetError()
	{
		return mysql_error(mysql_.get());
	}

	int MySQLConn::GetErrno()
	{
		return mysql_errno(mysql_.get());
	}
}