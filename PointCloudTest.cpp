/**
* @file   PointCloudTest.cpp
* @Author Selay Yirtimci
* @date    Ocak 2023
* @brief PointCloudTest sinifinin test kodudur.
*/

#include <iostream>
#include "Point.h"
#include "PointCloud.h"
using namespace std;

//!Bu fonksiyon bir PointCloud nesnesinin i�inde bulunan nokta say�s�n� ve her bir noktan�n koordinatlar�n� yazd�r�r
int TestPointCloud() {
    PointCloud PC(5);
    //!PointCloud nesnesinde bulunan nokta say�s�n� atar
    int pointnum = PC.GetPointNumber();

    list<Point> points;

    //!PointCloud nesnesi olusturulur
    PointCloud PC3(0);
    PointCloud PC2(0);
	PointCloud PC1(0);
    Point p, p1, p2;

	p.setX(1);
	p.setY(3);
	p.setZ(5);

	p1.setX(2);
	p1.setY(4);
	p1.setZ(6);

    p2.setX(9);
    p2.setY(0);
    p2.setZ(9);


    //Point nesnesine ekleme yapar
    points.push_back(p);
    points.push_back(p1);
    PC1.SetPoints(points);
    points.push_back(p2);
    PC2.SetPoints(points);

    //!PC1 ve PC2 nokta bulutlar�n�n toplam� olu�turulan bir PointCloud nesnesi olu�tur
    PC3 = PC1 + PC2;

    PC2.SetPointNumber(2);
    PC3.GetPoints();

    return 10;
}
