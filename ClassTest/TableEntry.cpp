#include "TableEntry.h"

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

TableEntry::TableEntry(std::string str):_num(0)
{
	istringstream iss(str);
	TableElement tele;
	while (tele.SetElement(_types[_num]), iss>>tele)
	{
		_entry.push_back(tele);
		_num++;
	}
}

TableEntry::TableEntry(vector<TableElement>& vtele):_num(0)
{
	_entry = vtele;
	_num = vtele.size();
}

void TableEntry::SetElementType(std::string str)
{
	int i = 0;
	string type;
	istringstream iss(str);
	while (iss >> type)
	{
		_types.push_back(TableElement::StrToElementType(type));
		++i;
	}

	assert(i == _num);
}

void TableEntry::SetElementType(std::vector<ElementType>& vet)
{
	_types = vet;
}

void TableEntry::SetElementNum(int n)
{
	_num = n;
	_entry.resize(n);
}

void TableEntry::SetElementVal(int col, TableElement &ele)
{
	assert(col < _num);

	_entry[col] = ele;
}

TableElement& TableEntry::GetElementVal(int col)
{
	assert(col < _num);

	return _entry[col];
}

std::ostream& operator<<(std::ostream& out, const TableEntry& te)
{
	for (int i=0; i<te._num; ++i)
		out << te._entry[i] << " ";
	out << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, TableEntry& te)
{
	for (int i=0; i<te._num; i++)
	{
		te._entry[i].SetElement(te._types[i]);
		in >> te._entry[i];
	}
	return in;
}
