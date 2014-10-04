#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape
{
public:
	Shape(void);
	virtual ~Shape(void);

	virtual void Draw() = 0;
};

class Circle: public Shape
{
public:
	Circle();
	~Circle();
	void Draw();
};

class Rectangle: public Shape
{
public:
	Rectangle();
	~Rectangle();
	void Draw();
};

class Square: public Shape
{
public:
	Square();
	~Square();
	void Draw();
};

#endif //_SHAPE_H_