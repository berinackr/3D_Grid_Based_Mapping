/**
* @file		: DepthCamera.cpp
* @Author	: Berna ÇAKIR
* @date		: 05.01.2023
*/

#include <iostream>
#include"DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
using namespace std;

//Depth camera fonksiyonlari icin test fonksiyonu
int DephtCameraTest()
{
	//2 pointCloud olusturulur
	PointCloud pointcloud1(0), pointcloud2(0);

	//cam.txt noktalarý nokta bulutu yapar
	DepthCamera dc("cam.txt");
	dc.getFileName();
	pointcloud1 = dc.capture();

	//Nokta bulutundaki noktalari cagirir
	pointcloud1.GetPoints();

	//cam2.txt noktalarý nokta bulutu olusturur ve transform yapar
	dc.setFileName("cam2.txt");
	pointcloud2 = dc.captureFor();

	//Nokta bulutundaki noktalari cagirir
	pointcloud2.GetPoints();
	cout << "DephtCameraTest fonksiyonu calisti" << endl;
	return 10;
}