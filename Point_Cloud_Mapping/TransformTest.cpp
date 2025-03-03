/**
* @file		: TransformTest.cpp
* @Author	: Berna ÇAKIR, Hilal BAYRAMOGLU, Selay YIRTIMCI , Yakup YUCE
* @date		: 05.01.2023
*/
#include<iostream>
#include<iomanip>
#include "Transform.h"
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"

using namespace std;

//Transform fonksiyonlari icin test fonksiyonu
int TransformTest()
{
	// Point Cloud olusturulur
	PointCloud pc1(0);

	//cam.txt noktalarý nokta bulutu yapar
	DepthCamera c1("cam.txt");
	pc1 = c1.capture();

	Transform transform;

	//Transform set fonksiyonlarý kontrol
	transform.set_trans(20, 20, 15);
	transform.set_angles(80, -180, -45);
	transform.setRotation(transform.get_angles());
	transform.setTranslation(transform.get_trans());

	PointCloud tempPC(0);

	//Transform doTransform fonksiyonu kontrol
	tempPC = transform.doTransform(pc1);

	cout << "TransformTest fonksiyonu calisti" << endl;
	return 10;
}