/**
* @file   PointCloudRecorderTest.cpp
* @Author Hilal Bayramoglu
* @date Ocak 2023
* @brief PointCloudRecorder sinifinin test kodudur.
*/

#include "Point.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int PointCloudRecorderTest() {

	//!PointCloudRecorder nesnesi olusturulur.
	PointCloudRecorder pcr;

	//!Point nesneleri olusturulur.
	Point p1, p2, p3;
	p1.setX(0.14288870);
	p1.setY(0.13210465);
	p1.setZ(2.98855591);
	p2.setX(0.14504044);
	p2.setY(0.12921785);
	p2.setZ(2.92324877);
	p3.setX(0.14851032);
	p3.setY(0.12766677);
	p3.setZ(2.88815951);
	//!PointCloud nesneleri olusturulur.
	PointCloud pc(3);
	pc.SetPoint(p1);
	pc.SetPoint(p2);
	pc.SetPoint(p3);

	pcr.setFileName("fNameDeneme.txt");
	pcr.getFileName();
	pcr.save(pc);

	cout << "PointCloudRecorderTest fonksiyonu calisti" << endl;
	return 10;

}