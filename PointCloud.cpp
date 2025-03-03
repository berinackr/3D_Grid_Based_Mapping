/**
* @file		: PointCloud.cpp
* @Author	: Selay YIRTIMCI
* @date		: Ocak 2023
*/
#include "PointCloud.h"

/*@Brief		:Kurucu fonksiyondur.
@Param			:Parametre olarak point dizisinin eleman sayisini alir */
PointCloud::PointCloud(int _pointNumber = 0) {
	pointNumber = _pointNumber;
}

/*Yikici Fonksiyondur.*/
PointCloud::~PointCloud()
{
}


/*@Brief		:Point listesi olusturma fonksiyonu.Bir deger döndürmez.
@Param			:Point turunde bir list alir. */
void PointCloud::SetPoints(list<Point> pc)
{
	points.clear();
	this->points = pc;
	pointNumber = pc.size();
}

/*@Brief		:Listeye bir point ekler.
@Param			:Point turunde degisken alýr*/
void PointCloud::SetPoint(Point p) {
	
	points.push_back(p);
	pointNumber++;

}

/*@Brief      :Point listesini cagýrma fonksiyonu.
Point list turunde bir nesne dondurur*/
list<Point> PointCloud::GetPoints() const
{
	return this->points;
}


/* @Brief           :Point listesine eleman ekleme fonksiyonudur.
Bir deger dondurmez .
@Param				:Tamsayi(int) bir deger alir*/
void PointCloud::SetPointNumber(int num)
{
	this->pointNumber = num;
}

/*@Brief        :Point listesi eleman sayisini cagirma fonksiyonudur.
eleman sayisini tamsayi(int) olarak dondurur
@ Param         :Bir deger almaz */
int PointCloud::GetPointNumber() const
{
	return this->pointNumber;
}

/*@Brief		: 2 nokta bulutunun elemanlarini toplar.
 2 nesneyi toplayarak yine pointcloud turunde bir nesne dondurur
@Param			:Pointcloud turunde bir nesne alir.*/
PointCloud PointCloud::operator+(const PointCloud& point_cloud)
{
	list<Point> P1, P2, P3;
	list<Point>::iterator iter1, iter2;

	PointCloud temp;
	P1 = this->GetPoints();
	P2 = point_cloud.GetPoints();
	temp.SetPointNumber(P1.size() + P2.size());
	iter1 = P1.begin();
	iter2 = P2.begin();
	for (int i = 0; i < P1.size() + P2.size(); i++)
	{
		if (i < P1.size())
		{
			P3.push_back(*iter1++);
		}
		else
		{
			P3.push_back(*iter2++);
		}
	}
	temp.SetPoints(P3);
	return temp;
}

/*@Brief		:Nokta bulutunun elemanlarini kopyalar .
@Param			:ve 2 nesneyi esitler
Pointcloud turunde bir nesne alir. */
void PointCloud::operator=(PointCloud* PC) {
	list<Point>::iterator iter;
	for (iter = this->points.begin(); iter != this->points.end(); iter++) {
		PC->points.push_back(*iter);
	}
}
