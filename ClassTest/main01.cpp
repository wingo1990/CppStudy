#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Table.h"
#include "TableElement.h"
#include "TableEntry.h"

bool ElementEqual(TableEntry& te, int n, TableElement& tele)
{
	if (te.GetElementVal(n) == tele)
		return true;
	else
		return false;
}

int main()
{
	// create table			ok
	// open table			ok
	// delete entry			ok
	// select entries
	// insert entries		ok
	// close table			ok
	Table *table = GetTableInstance(FILE_TABLE);
	//table->CreateTable("test_table.txt", "name-string old-int phone-string address-string");
	table->OpenTable("test_table.txt");
	
	//table->InsertEntry("zhangfeng 23 17756564321 beijing");
	//table->InsertEntry("zhanghua 24 1234567890 suzhou");


	//table->DeleteEntry(0);
	//TableElement te("zhangfeng");
	//
	//table->DeleteEntry(SELECT_EQUAL, 0, te);

	Results res;
	TableElement tele("suzhou");
	table->SelectEntry(res, SELECT_EQUAL, 3, tele);

	for (int i=0; i<res.size(); i++)
	{
		cout << res.next();
	}

	table->CloseTable();

	//delete table;

	return 0;
}