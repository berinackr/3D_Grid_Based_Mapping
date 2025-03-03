/**
* @file		: PointCloud.h
* @Author	: Selay YIRTIMCI
* @date		:Ocak 2023
*/
#pragma once
#include"Point.h"
#include<list>

using namespace std; 

class PointCloud
{
private:
	//Point diziniz eleman sayisini tutar 
	int pointNumber;
	//Point turunde bir liste.
	list<Point> points;
public:
	//Kurucu fonksiyon
	PointCloud(int);
	//Yikici fonksiyon
	~PointCloud();
	// Nokta bulutuna nokta ekleme foksiyonlari
	void SetPoint(Point);
	void SetPoints(list<Point> pc);
	// Eleman sayisi ekleme fonksiyonu
	void SetPointNumber(int);
	//Belirli bir nokta cagirma fonksiyonu
	list<Point> GetPoints() const;
	//Nokta sayisi cagirma fonksiyonu
	int GetPointNumber() const;
	//2 nokta bulutunu toplama fonksiyonu
	PointCloud operator+(const PointCloud&);
	//Nokta bulutlarini kopyalama fonksiyonu
	void operator=(PointCloud* PC);
};
