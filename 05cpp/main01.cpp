#include "Shape.h"
#include "DynFactory.h"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	Shape *sp;

	sp = (Shape*)DynFactory::CreateObject("Circle");
	sp->Draw();

	sp = (Shape*)DynFactory::CreateObject("Rectangle");
	sp->Draw();

	sp = (Shape*)DynFactory::CreateObject("Square");
	sp->Draw();
	
}

REGISTER_CLASS(Rectangle);
REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);