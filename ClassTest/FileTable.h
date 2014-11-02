#ifndef _FILE_TABLE_H_
#define _FILE_TABLE_H_

//file table column number.
#define FTCN "FTCN:"
#define FTCN_LEN 5

//file table entry number.
#define FTEN "FTEN:"
#define FTEN_LEN 5

#include <vector>

#include "Table.h"
#include "TableEntry.h"
#include "TableElement.h"


/*
		table file format
//version:x.x
//time:2014/09/34-21:34
...
FTCN:n\n
name-type name-type name-type			  ...... \n
...
FTEN:n\n
TableEntry[TableElement TableElement ...]		 \n
TableEntry[TableElement TableElement ...]		 \n
TableEntry[TableElement TableElement ...]		 \n
TableEntry[TableElement TableElement ...]        \n
TableEntry[TableElement TableElement ...]		 \n
...
...

*/

class FileTable : public Table
{
public:
	// open file to get table data, then close it.
	void OpenTable(TableName);

	// flush data to file, then clear the obj.
	void CloseTable();

	// create file in which there are some column name and its type.
	// importantly the table is default open, then you must close it.
	void CreateTable(TableName, const std::vector<ColumnName>& vcln);
	void CreateTable(TableName, std::string sclns);
	// delete file
	void DeleteTable(TableName);

	// attach to the end.
	void InsertEntry(std::string);
	void InsertEntry(const TableEntry&);
	// insert to the position before the id.
	void InsertEntry(EntryID&, std::string);
	void InsertEntry(EntryID&, const TableEntry&);

//	void SetColumnName(const std::vector<ColumnName>&);
	void AddColumn(const ColumnName&, ColumnID id = -1);
	void AddColumn(std::string, ColumnID id = -1);
	void DelColumn(const ColumnName&);
	void DelColumn(std::string);
	void DelColumn(const ColumnID&);

	bool UpdateEntry(const TableEntry&, EntryID);
	bool UpdateEntry(std::string, EntryID);

	void SelectEntry(TableEntry&, EntryID);
	void SelectEntry(Results&, SlectCondition, ColumnID, TableElement&);

	void DeleteEntry(EntryID id);
	void DeleteEntry(SlectCondition, ColumnID, TableElement&);


	FileTable(): _tn(""), _col_num(0), _entry_num(0){}
	~FileTable(void){}

private:
	TableName _tn;
	int _col_num;
	int _entry_num;

	// TODO do not have interface to modify.
	static std::string TableDir;

	// vector subscript default is used as id.
	// easily to realize Insert function.
	std::vector<TableEntry> _entries;

	//vector use inflexibly.
	std::vector<ColumnName> _col_names;

	// save to file
	void TableFlush() const;
	// clear object table
	void TableClear();

	void ColNamesFromFile(std::ifstream&);
	void EntriesFromFile(std::ifstream&);
	void ColNamesToFile(std::ofstream&) const;
	void EntriesToFile(std::ofstream&) const;
	bool PreC(EntryID, SlectCondition, ColumnID, TableElement&); 

	inline void StrToColName(std::string&, ColumnName&);
	inline void StrToEntry(std::string&, TableEntry&);
	inline int ColNum(std::string&);
	inline bool IsTableExist(std::string);
	inline std::vector<ElementType> TypesOneEntry();
};

#endif // _FILE_TABLE_H_

