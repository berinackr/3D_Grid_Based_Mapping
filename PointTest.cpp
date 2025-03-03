/**
* @file		: PointTest.cpp
* @Author	: Yakup Yuce (y4kupyuce@gmail.com)
* @date		: Ocak 2023
*/

#include <iostream>
#include "Point.h"

using namespace std;

int PointTest()
{
	//Point icin test kodu.
	Point p1, p2, p3;
	p2.setX(1);
	p2.setY(3);
	p2.setZ(5);

	double x = 0, y = 0, z = 0;
	p1.setX(x);
	p1.setY(y);
	p1.setZ(z);

	p3.setX(p1.getX());
	p3.setY(p1.getY());
	p3.setZ(p1.getZ());

	p1 = p2;
	
	p3.distance(p2);

	cout << "PointTest fonksiyonu calisti" << endl;
	return 10;
}