#ifndef _TABLE_ELEMENT_H_
#define _TABLE_ELEMENT_H_

#include <iostream>

typedef enum tagElementType
{
	ElementTypeNULL,
	ElementString,
	ElementInt,
	ElementDouble,
}ElementType;

class TableElement
{
public:
	TableElement();
	TableElement(const TableElement &);
	TableElement(const int &i);
	TableElement(const double &d);
	TableElement(const std::string &str);
	//TableElement(const bool &b);
	
	~TableElement();

	void SetElement(std::string&);
	void SetElement(ElementType);

	TableElement &operator=(const TableElement &);
	friend std::ostream &operator<<(std::ostream &, const TableElement &);
	friend std::istream &operator>>(std::istream &, TableElement &);
	bool operator==(const int&);
	bool operator==(const std::string&);
	bool operator==(const double&);
	bool operator==(const TableElement&);
	
	bool operator<(const TableElement&);
	bool operator>(const TableElement&);

	static ElementType StrToElementType(std::string&);

private:
	ElementType _eletype;
	void* _eleptr;
	void *CreateElement();
	void CopyElement(void *dst, void *src);
	void ElementOut(std::ostream &) const;
	void ElementIn(std::istream &);
	bool ElementLess(void *);
	bool ElementEqual(void *);
	bool ElementGreater(void *);
};

#endif  //_TABLE_ELEMENT_H_