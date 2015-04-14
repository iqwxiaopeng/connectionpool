#ifndef MYSQL_RESULT_H
#define MYSQL_RESULT_H
#include <mysql/mysql.h>
#include <resultset_metadata.h>
namespace yang
{
	typedef int64_t ROW_OFFSET;
	class MySQLRes
	{
	public:
		MySQLRes(MYSQL_RES *result):result_(result){}
		~MySQLRes();
		bool Absolute(int row);
		void AfterLast();
		void BeforeFirst();
		void Close();
		bool First();
		bool GetBool(uint32_t columnIndex);
		int32_t GetInt(uint32_t columnIndex);
		uint32_t GetUint(uint32_t columnIndex);
		int64_t GetInt64(uint32_t columnIndex);
		uint64_t GetUint64(uint32_t columnIndex);
		const char* GetString(uint32_t columnIndex);
		ResultSetMetaData * getMetaData();
		bool IsAfterLast() const;
		bool IsBeforeFirst() const;
		bool IsClosed() const;
		bool IsFirst() const;
		bool IsLast() const;
		bool IsNull(uint32_t columnIndex) const;
		int GetNumField();
		bool Last();
		int Next();
		uint64_t GetNumRows();
		ROW_OFFSET RowSeek(ROW_OFFSET offset);
		ROW_OFFSET RowTell();
	private:
		MYSQL_RES *result_;
	};
}
#endif