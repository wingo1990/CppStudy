#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(void)
{
}


Shape::~Shape(void)
{
}

Circle::Circle()
{
	cout << "Circle ..." << endl;
}
Circle::~Circle()
{
	cout << "~Circle ..." << endl;
}
void Circle::Draw()
{
	cout << "Draw Circle ..." << endl;
}

Rectangle::Rectangle()
{
	cout << "Rectangle ..." << endl;
}
Rectangle::~Rectangle()
{
	cout << "~Rectangle ..." << endl;
}
void Rectangle::Draw()
{
	cout << "Draw Rectangle ..." << endl;
}

Square::Square()
{
	cout << "Square ..." << endl;
}
Square::~Square()
{
	cout << "~Square ..." << endl;
}
void Square::Draw()
{
	cout << "Draw Square ..." << endl;
}
