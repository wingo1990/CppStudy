#include <iostream>

#include "Table.h"
#include "FileTable.h"


using namespace std;

Table *GetTableInstance(XTable xt)
{
	if (xt == FILE_TABLE)
		return new FileTable();
	else
		;//return new DBTable();
}


std::ostream& operator<<(std::ostream& out, const ColumnName& pair)
{
	out << pair.name << "-" << pair.type;

	return out;
}

std::istream& operator>>(std::istream& in, ColumnName& pair)
{
	std::string pairstr;

	in >> pairstr;
	int pos = pairstr.find("-");
	if (pos == std::string::npos)
		return in;

	// TODO, if pair data use other separators not [ \t], that will be a bug.
	pair.name.assign(pairstr, 0, pos);
	pair.type.assign(pairstr, pos+1, -1);

	return in;
}

std::ostream& operator<<(std::ostream& out, const ResultEntry& te)
{
	out << te.id << " " << te.tblentry;
	return out;
}

std::istream& operator>>(std::istream& in, ResultEntry& te)
{
	in >> te.id >> te.tblentry;
	return in;
}

ResultEntry& Results::next()
{
	int index = _next;
	if(_next < size()-1)
		_next++;
	else 
		_next = 0;
	return _res[index];
}

const int Results::size() const
{
	return _res.size();
}

void Results::add(EntryID id, TableEntry &te)
{
	ResultEntry re;
	re.id = id;
	re.tblentry = te;
	_res.push_back(re);
}