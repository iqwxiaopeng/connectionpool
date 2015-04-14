#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H
#include <stdio.h>
#include <memory>
#include <mysql/mysql.h>
#include <mysql_result.h>
namespace yang
{

	typedef std::shared_ptr<MySQLRes> ResultSet;
	typedef std::shared_ptr<MYSQL> MySQL;
	class DeleteMySQL
	{
	public:
		void operator()(MYSQL *mysql)
		{
			printf("mysql close");
			mysql_close(mysql);
		}
	};

	class MySQLConn
	{
	public:
		MySQLConn() : mysql_(mysql_init(NULL), DeleteMySQL())
			, connecting_(false){};
		~MySQLConn() {};
		int Connect(const char *host, const char *user,
			        const char *pwd, int port, const char *db = NULL);
		bool Connecting() const { return connecting_; }
		int Execute(const char *sql);
		ResultSet ExecuteQuery(const char *sql);
	private:
		ResultSet result_;
		MySQL mysql_;
		bool connecting_;
	};
}
#endif