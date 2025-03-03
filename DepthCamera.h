/**
* @file		: DepthCamera.h
* @Author	: Berna ÇAKIR
* @date		: 05.01.2023
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "PointCloud.h"
#include"PointCloudGenerator.h"


//DepthCamera sinifi
class DepthCamera : public PointCloudGenerator{
private:
	string fileName;
public:
	// Constructor fonksiyonu
	DepthCamera(string);
	// Destructor fonksiyonu
	~DepthCamera();
	// Dosya ismi atama fonksiyonu
	void setFileName(string);
	// Dosya ismi çagirma fonksiyonu
	string getFileName();
	// Dosyadaki noktalarý nokta bulutu olarak döndüren fonksiyon
	PointCloud capture();
	// Dosyadaki noktalarý nokta bulutuna cevirip transform yapan fonksiyon
	PointCloud captureFor();
};