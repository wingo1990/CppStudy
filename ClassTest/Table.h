#ifndef _TABLE_H_
#define _TABLE_H_

#include <fstream>
#include <string>
#include <vector>

#include "TableEntry.h"

typedef std::string TableName;
typedef int	EntryID;
typedef int ColumnID;

typedef enum tagXtableEnum
{
	DB_TABLE,
	FILE_TABLE,
	DEFAULT_TABLE = FILE_TABLE
}XTable;

typedef enum tagSelectCondition
{
	SELECT_LESS,
	SELECT_EQUAL,
	SELECT_GREATER
	//continue condition to be consider.
}SlectCondition;

// Results format
class ResultEntry
{
public:
	EntryID id;
	TableEntry tblentry;

	friend std::ostream& operator<<(std::ostream&, const ResultEntry&);
	friend std::istream& operator>>(std::istream&, ResultEntry&);
};

// must use  \t and some other blank separators to split pair data.
class ColumnName
{
public:
	ColumnName(){}
	ColumnName(const std::string& n, const std::string& t): name(n), type(t) {}
	ColumnName(const char*&pn, const char*&pt):name(pn), type(pt) {}
	bool operator==(const ColumnName& other){ return(name == other.name && type == other.type);	}
	friend std::ostream& operator<<(std::ostream &, const ColumnName&);
	friend std::istream& operator>>(std::istream &, ColumnName&);

	// could not has '-', it is a split.
	std::string name;
	std::string type;
};

class Results
{
public:
	Results():_next(0) {}
	~Results(){}

	ResultEntry& next();

	const int size() const;

	void add(EntryID id, TableEntry &te);

private:
	int _next;
	std::vector<ResultEntry> _res;
};

class Table
{
public:
	typedef bool (*Pred)(TableEntry&, int, TableElement&);

	virtual void OpenTable(TableName) = 0;
	virtual void CloseTable() = 0;

	virtual void CreateTable(TableName, const std::vector<ColumnName>& vcln) = 0;
	virtual void CreateTable(TableName, std::string sclns) = 0;
	virtual void DeleteTable(TableName) = 0;

	virtual void InsertEntry(std::string) = 0;
	virtual void InsertEntry(EntryID&, std::string) = 0;
	virtual void InsertEntry(const TableEntry&) = 0;
	virtual void InsertEntry(EntryID&, const TableEntry&) = 0;

//	virtual void SetColumnName(const std::vector<ColumnName>&) = 0;
	virtual void AddColumn(const ColumnName&, ColumnID id = -1) = 0;
	virtual void AddColumn(std::string, ColumnID id = -1) = 0;
	virtual void DelColumn(const ColumnName&) = 0;
	virtual void DelColumn(std::string) = 0;
	virtual void DelColumn(const ColumnID&) = 0;

	virtual bool UpdateEntry(const TableEntry&, EntryID) = 0;
	virtual bool UpdateEntry(std::string, EntryID) = 0;

	virtual void SelectEntry(TableEntry&, EntryID) = 0;
	virtual void SelectEntry(Results&, SlectCondition, ColumnID, TableElement&) = 0;

	virtual void DeleteEntry(EntryID id) = 0;
	virtual void DeleteEntry(SlectCondition, ColumnID, TableElement&) = 0;
};

Table *GetTableInstance(XTable xt=DEFAULT_TABLE);

//
//inline Table* CreateTable(const Table::TableName& tn, const std::vector<ColumnName>& vcln)
//{
//	FileTable *ft = new FileTable(tn);
//
//	ft->SetColumnName(vcln);
//
//	return ft;
//}
//
//inline Table* CreateTable(Table::TableName& tn, std::string sclns)
//{
//	FileTable *ft = new FileTable(tn);
//
//	std::vector<ColumnName> vcln;
//	std::string scln;
//	std::ifstream iss(sclns);
//	while (iss >> scln)
//		ft->AddColumnName(scln);
//
//	return ft;
//}
//
//inline Table* OpenTable(Table::TableName & tn)
//{
//	FileTable *ft = new FileTable(tn);
//	ft->OpenTable();
//
//	return ft;
//}
//
//inline void CloseTable(Table *& ft)
//{
//	ft->CloseTalbe();
//
//	delete ft;
//	ft = 0;
//}
#endif //_TABLE_H_
