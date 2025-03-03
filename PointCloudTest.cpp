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

//!Bu fonksiyon bir PointCloud nesnesinin içinde bulunan nokta sayýsýný ve her bir noktanýn koordinatlarýný yazdýrýr
int TestPointCloud() {
    PointCloud PC(5);
    //!PointCloud nesnesinde bulunan nokta sayýsýný atar
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

    //!PC1 ve PC2 nokta bulutlarýnýn toplamý oluþturulan bir PointCloud nesnesi oluþtur
    PC3 = PC1 + PC2;

    PC2.SetPointNumber(2);
    PC3.GetPoints();

    return 10;
}
