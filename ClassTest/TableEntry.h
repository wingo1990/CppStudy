#ifndef _TABLE_ENTRY_H_
#define _TABLE_ENTRY_H_

#include <vector>
#include <iostream>

#include "TableElement.h"

class TableEntry
{
public:
	TableEntry():_num(0){}
	~TableEntry(){};
	TableEntry(std::string);
	TableEntry(std::vector<TableElement>&);

	void SetElementType(std::string);
	void SetElementType(std::vector<ElementType>&);

	void SetElementNum(int);

	void SetElementVal(int, TableElement &);
	TableElement& GetElementVal(int);

	friend std::ostream& operator<<(std::ostream&, const TableEntry&);
	friend std::istream& operator>>(std::istream&, TableEntry&);

private:
	int _num;
	std::vector<TableElement> _entry;
	std::vector<ElementType> _types;
};

#endif //_TABLE_ENTRY_H_

