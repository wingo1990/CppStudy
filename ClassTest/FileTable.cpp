#include <fstream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <cstdio>

#include "FileTable.h"
#include "TableEntry.h"

using namespace std;

std::string FileTable::TableDir = "F:\\Temp\\";

void FileTable::OpenTable(TableName tn)
{
	assert(IsTableExist(tn));

	_tn = tn;

	// open file stream.
	ifstream tablestream(TableDir+_tn, ios::binary);
	assert(tablestream);
	// set _column_names.
	ColNamesFromFile(tablestream);

	// set _entries.
	EntriesFromFile(tablestream);

	//close file stream.
	tablestream.close();
}

void FileTable::CloseTable()
{
	TableFlush();
	TableClear();
}

void FileTable::CreateTable(TableName tn, const vector<ColumnName>& vcln)
{
	assert(!IsTableExist(tn));

	_tn = tn;
	_col_names = vcln;
	_col_num = vcln.size();
//	TableFlush();
}

void FileTable::CreateTable(TableName tn, std::string sclns)
{
	assert(!IsTableExist(tn));

	_tn = tn;

	std::vector<ColumnName> vcln;
	std::string scln;
	std::istringstream iss(sclns);
	while (iss >> scln)
		AddColumn(scln);
}

void FileTable::DeleteTable(TableName tn)
{
	remove((TableDir+tn).c_str());
}

// void FileTable::SetColumnName(const std::vector<ColumnName>& colname)
// {
// 	_col_names = colname;
// 	_col_num = colname.size();
// }

void FileTable::AddColumn(const ColumnName& colname, ColumnID id)
{
	if (id == -1)
		_col_names.push_back(colname);
	else
	{
		vector<ColumnName>::iterator it = _col_names.begin();
		it += id;
		_col_names.insert(it, colname);
	}
	++_col_num;
}
void FileTable::AddColumn(string scln, ColumnID id)
{
	ColumnName cn;
	StrToColName(scln, cn);
	AddColumn(cn, id);
}

void FileTable::DelColumn(const ColumnName& cn)
{
	vector<ColumnName>:: iterator it = find(_col_names.begin(), _col_names.end(), cn);
	_col_names.erase(it);
}
void FileTable::DelColumn(string scn)
{
	ColumnName cn;
	StrToColName(scn, cn);
	DelColumn(cn);
}
void FileTable::DelColumn(const ColumnID& id)
{
	vector<ColumnName>:: iterator it = _col_names.begin() + id;
	_col_names.erase(it);
}

void FileTable::InsertEntry(std::string se)
{
	TableEntry te(se);

	InsertEntry(te);
}

void FileTable::InsertEntry(const TableEntry& te)
{
	_entries.push_back(te);
	++_entry_num;
};

void FileTable::InsertEntry(EntryID& id, std::string se)
{
	assert(id <= _entry_num);

	TableEntry te(se);

	InsertEntry(id, te);
}

void FileTable::InsertEntry(EntryID& id, const TableEntry& te)
{
	assert(id <= _entry_num);

	vector<TableEntry>::iterator it;
	it = _entries.begin();
	it += id;

	_entries.insert(it, te);
	++_entry_num;
}

bool FileTable::UpdateEntry(const TableEntry& te, EntryID id)
{
	if (id < _entry_num)
	{
		_entries[id] = te;
		return true;
	}
	else
		return false;
}
bool FileTable::UpdateEntry(std::string se, EntryID id)
{
	TableEntry te(se);
	StrToEntry(se, te);
	return UpdateEntry(se, id);
}

void FileTable::SelectEntry(TableEntry& tble, EntryID id)
{
	assert(id < _entry_num);

	tble = _entries[id];
}

void FileTable::SelectEntry(Results& results, SlectCondition SC, ColumnID id, TableElement& te)
{
	for (int i=0; i<_entry_num; ++i)
		if (PreC(i, SC, id, te))
			results.add(id+i, _entries[i]);
}

void FileTable::DeleteEntry(EntryID id)
{
	assert(id < _entry_num);

	_entries.erase(_entries.begin() + id);

	_entry_num--;
}

void FileTable::DeleteEntry(SlectCondition SC, ColumnID id, TableElement& te)
{
	for (int i=0; i<_entry_num; )
		if (PreC(i, SC, id, te))
		{
			_entries.erase(_entries.begin() + i);	// [11/2/2014 wingo] must be very careful.
			_entry_num--;
		}
		else
			++i;
}

void FileTable::TableFlush() const
{
	ofstream tablestream(TableDir+_tn, ios::binary);
	assert(tablestream);

	// column names save to file.
	ColNamesToFile(tablestream);

	// entries save to file.
	EntriesToFile(tablestream);

	//close file stream.
	tablestream.close();
}

void FileTable::TableClear()
{
	_tn = "";

	_col_names.clear();
	_col_num = 0;

	_entries.clear();
	_entry_num = 0;
}

void FileTable::ColNamesFromFile(ifstream& ifs)
{
	// get FTCN line & get column number
	string rowstr;
	int pos = string::npos;
	while (getline(ifs, rowstr))
	{
		pos = rowstr.find(FTCN, 0);
		if (pos != string::npos)
			break;
	}

	assert(string::npos != pos);	
	rowstr.erase(pos, FTCN_LEN);
	istringstream iss(rowstr);
	iss >> _col_num;

	//set column names and its type
	_col_names.resize(_col_num);
	for (int i=0; i<_col_num; ++i)
		ifs >> _col_names[i];
}

void FileTable::EntriesFromFile(ifstream& ifs)
{//must run after SetColNamesFromFile. it is just a procedure.

	// set entry num.
	string rowstr;
	int pos = string::npos;
	while (getline(ifs, rowstr))
	{
		pos = rowstr.find(FTEN, 0);
		if (pos != string::npos)
			break;
	}

	assert(string::npos != pos);
	rowstr.erase(pos, FTEN_LEN);
	istringstream iss(rowstr);
	iss >> _entry_num;

	// set entry
	_entries.resize(_entry_num);
	vector<ElementType> vet = TypesOneEntry();
	for (int i=0; i<_entry_num; ++i)
	{
		//getline(ifs, rowstr);
		//istringstream iss_entry(rowstr);
		_entries[i].SetElementNum(_col_num);
		_entries[i].SetElementType(vet);
		ifs >> _entries[i];
	}
}

void FileTable::ColNamesToFile(std::ofstream& ofs) const
{
	// set FTCN
	ofs << FTCN << _col_num << "\n";
	
	// set column names
	for (int i=0; i<_col_num; ++i)
		ofs << _col_names[i] << " ";
	ofs << "\n";
}

void FileTable::EntriesToFile(std::ofstream& ofs) const
{
	// set FTEN
	ofs << FTEN << _entry_num << "\n";

	// set entries
	for (int i=0; i<_entry_num; ++i)
		ofs << _entries[i];
}

bool FileTable::PreC(EntryID eid, SlectCondition SC, ColumnID cid, TableElement& te)
{
	switch (SC)
	{
	case SELECT_LESS:
		return _entries[eid].GetElementVal(cid) < te;
	case SELECT_EQUAL:
		return _entries[eid].GetElementVal(cid) == te;
	case SELECT_GREATER:
		return _entries[eid].GetElementVal(cid) > te;
	default:
		assert(NULL);
		break;
	}

	return false;
}

inline bool FileTable::IsTableExist(std::string tn)
{
	ifstream ifs(TableDir+tn);
	if (ifs)
		return true;
	else
		return false;
}


inline void FileTable::StrToColName(std::string& scln, ColumnName& cn)
{
	int pos = scln.find('-');
	cn.name.assign(scln, 0, pos);
	cn.type.assign(scln, pos+1, scln.size()-pos-1);
}

inline void FileTable::StrToEntry(string& se, TableEntry& te)
{
	istringstream iss(se);
	iss >> te;
}

inline std::vector<ElementType> FileTable::TypesOneEntry()
{
	vector<ElementType> vet;
	for (int i=0; i<_col_num; i++)
		vet.push_back(TableElement::StrToElementType(_col_names[i].type));
	return vet;
}

//inline int FileTable::ColNum(string &se)
//{
//	istringstream iss(se);
//	TableElement tele;
//	int n = 0;
//	while (iss >> tele)	++n;
//
//	return n;
//}