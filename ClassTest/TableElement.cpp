#include <string>
#include <cassert>

#include "TableElement.h"

TableElement::TableElement():_eletype(ElementTypeNULL), _eleptr(0)
{
}

TableElement::TableElement(const TableElement &ele):_eletype(ele._eletype), _eleptr(0)
{
	_eleptr = CreateElement();
	CopyElement(_eleptr, ele._eleptr);
}

TableElement::TableElement(const int &i):_eletype(ElementInt), _eleptr(0)
{
	_eleptr = CreateElement();
	*(int*)_eleptr = i;
}

TableElement::TableElement(const double &d):_eletype(ElementDouble), _eleptr(0)
{
	_eleptr = CreateElement();
	*(double*)_eleptr = d;
}

TableElement::TableElement(const std::string &str):_eletype(ElementString), _eleptr(0)
{
	_eleptr = CreateElement();
	*(std::string*)_eleptr = str;
}

TableElement::~TableElement()
{
	if (_eleptr != 0)
		delete _eleptr;
}

void TableElement::SetElement(std::string& str)
{
	SetElement(StrToElementType(str));
}

void TableElement::SetElement(ElementType et)
{
	_eletype = et;
	if (_eleptr != 0)
	{
		delete _eleptr;
		_eleptr = 0;
	}

	_eleptr = CreateElement();
}

TableElement &TableElement::operator=(const TableElement &ele)
{
	SetElement(ele._eletype);

	CopyElement(_eleptr, ele._eleptr);

	return *this;
}

std::ostream &operator<<(std::ostream &out, const TableElement &ele)
{
	assert(ele._eletype != ElementTypeNULL);
	assert(ele._eleptr != NULL);

	ele.ElementOut(out);

	return out;
}
std::istream &operator>>(std::istream &in, TableElement &ele)
{
	assert(ele._eletype != ElementTypeNULL);
	assert(ele._eleptr != NULL);
	//ele._eleptr = ele.CreateElement();
	ele.ElementIn(in);
	return in;
}

bool TableElement::operator==(const int& n)
{
	return (n == *(int*)_eleptr);
}

bool TableElement::operator==(const std::string &str)
{
	return (str == *(std::string*)_eleptr);
}

bool TableElement::operator==(const double& d)
{
	return (d == *(double*)_eleptr);
}

bool TableElement::operator==(const TableElement &tele)
{
	if (_eleptr == tele._eleptr)
		return true;
	else if (_eletype == tele._eletype)
		return ElementEqual(tele._eleptr);
	else
		return false;
}

bool TableElement::operator<(const TableElement& tele)
{
	assert(_eletype == tele._eletype);

	return ElementLess(tele._eleptr);
}

bool TableElement::operator>(const TableElement& tele)
{
	assert(_eletype == tele._eletype);

	return ElementGreater(tele._eleptr);
}

void* TableElement::CreateElement()
{
	if (_eleptr != 0)
		return _eleptr;

	switch (_eletype)
	{
	case ElementInt:
		return new int;
		break;
	case ElementDouble:
		return new double;
		break;
	case ElementString:
		return new std::string;
		break;
	default:
		break;
	}

	return 0;
}

void TableElement::CopyElement(void *dst, void *src)
{
	assert(dst != 0 && src != 0);

	switch (_eletype)
	{
	case ElementInt:
		*(int*)dst = *(int*)src;
		break;
	case ElementDouble:
		*(double*)dst = *(double*)src;
		break;
	case ElementString:
		*(std::string*)dst = *(std::string*)src;
		break;
	default:
		break;
	}
}

void TableElement::ElementOut(std::ostream &out) const
{
	assert(_eleptr != 0);

	switch (_eletype)
	{
	case ElementInt:
		out << *(int*)_eleptr;
		break;
	case ElementDouble:
		out << *(double*)_eleptr;
		break;
	case ElementString:
		out << *(std::string*)_eleptr;
		break;
	default:
		break;
	}
}

void TableElement::ElementIn(std::istream &in)
{
	assert(_eleptr != 0);

	switch (_eletype)
	{
	case ElementInt:
		in >> *(int*)_eleptr;
		break;
	case ElementDouble:
		in >> *(double*)_eleptr;
		break;
	case ElementString:
		in >> *(std::string*)_eleptr;
		break;
	default:
		break;
	}
}

bool TableElement::ElementLess(void *ptr)
{
	assert(ptr != NULL && _eleptr != NULL);

	switch (_eletype)
	{
	case ElementInt:
		return *(int*)_eleptr < *(int*)ptr;
	case ElementDouble:
		return *(double*)_eleptr < *(double*)ptr;
	case ElementString:
		return *(std::string*)_eleptr < *(std::string*)ptr;
	default:
		return false;		
	}
}

bool TableElement::ElementEqual(void *ptr)
{
	assert(ptr != NULL && _eleptr != NULL);

	switch (_eletype)
	{
	case ElementInt:
		return *(int*)ptr == *(int*)_eleptr;
	case ElementDouble:
		return *(double*)ptr == *(double*)_eleptr;
	case ElementString:
		return *(std::string*)ptr == *(std::string*)_eleptr;
	default:
		return false;		
	}
}

bool TableElement::ElementGreater(void *ptr)
{
	assert(ptr != NULL && _eleptr != NULL);

	switch (_eletype)
	{
	case ElementInt:
		return *(int*)_eleptr > *(int*)ptr;
	case ElementDouble:
		return *(double*)_eleptr > *(double*)ptr;
	case ElementString:
		return *(std::string*)_eleptr > *(std::string*)ptr;
	default:
		return false;		
	}
}

ElementType TableElement::StrToElementType(std::string& str)
{
	if (str == "int")
		return ElementInt;
	else if (str == "double")
		return ElementString;
	else if (str == "string")
		return ElementString;
	else
		return ElementTypeNULL;
}
