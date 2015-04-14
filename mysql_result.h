#ifndef MYSQL_RESULT_H
#define MYSQL_RESULT_H
#include <mysql/mysql.h>
namespace yang
{

	class MySQLRes
	{
	public:
		MySQLRes(MYSQL_RES *result):result_(result){}
		const char* GetString(){ MYSQL_ROW row = mysql_fetch_row(result_); return row[0]; }
	private:
		MYSQL_RES *result_;
	};
}
#endif