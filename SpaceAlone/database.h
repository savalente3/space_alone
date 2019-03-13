#ifndef database_h
#define database_h

#include "CppSQLite3.hpp"
#include <iostream>
#include <string>

CppSQLite3DB db;

bool getDatabase(const std::string path)
{
	try
	{
		db.open(path.c_str());
		return true;
	}
	catch (CppSQLite3Exception e)
	{
		std::cout << "Cannot open database: " << path << "\n";
		return false;
	}
}

void query(const std::string queryString)
{
	try
	{
		CppSQLite3Query q = db.execQuery(queryString.c_str());
		while (!q.eof())
		{
			// do something
			std::cout << "done!" << std::endl;
		}
	}
	catch (CppSQLite3Exception e)
	{
		std::cout << "Cannot execute query: " << queryString << "\n";
	}
}

#endif
