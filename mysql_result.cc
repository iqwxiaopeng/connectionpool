#include <mysql_result.h>
#include <stdio.h>
namespace yang
{
	const char* MySQLRes::GetString(int i)
	{
		MYSQL_ROW row = mysql_fetch_row(result_);
		if (!row) { return NULL; }
		return row[i]; 
	}

	MySQLRes::~MySQLRes()
	{
		mysql_free_result(result_);
	}
	
}