#ifndef MYSQL_RESULT_H
#define MYSQL_RESULT_H
#include <mysql/mysql.h>
namespace yang
{
	typedef int64_t ROW_OFFSET;
	class MySQLRes
	{
	public:
		MySQLRes(MYSQL_RES *result):result_(result){}
		~MySQLRes();
		const char* GetString(int i);
		int GetNumField();
		int NextResult();
		uint64_t GetNumRows();
		ROW_OFFSET RowSeek(ROW_OFFSET offset);
		ROW_OFFSET RowTell();
	private:
		MYSQL_RES *result_;
	};
}
#endif