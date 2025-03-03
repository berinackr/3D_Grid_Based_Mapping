/**
* @file		: Point.h
* @Author	: Yakup Yuce (y4kupyuce@gmail.com)
* @date		: Ocak 2023
*/

#pragma once
#include "Point.h"
#include<iostream>
#include<math.h>

//Point sinifi
class Point
{
private:
	//Noktanin x,y ve z koordinatlari
	double x, y, z;
public:
	//Kurucu fonksiyon
	Point();
	//Yikici fonksiyon
	~Point();
	//Noktainin koordinatlarini ekleme fonksiyonlari
	void setX(const double);
	void setY(const double);
	void setZ(const double);
	//Noktanin koordinatlarini cagirma fonksiyonlari
	double getX() const;
	double getY() const;
	double getZ() const;
	// Esitligi sorgulayan fonksiyon
	bool operator==(const Point& point) const;
	//uzaklik hesaplayan fonksiyon
	double distance(const Point& point) const;
};

