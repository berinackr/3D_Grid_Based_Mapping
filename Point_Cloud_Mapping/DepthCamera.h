/**
* @file		: DepthCamera.h
* @Author	: Berna �AKIR
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
	// Dosya ismi �agirma fonksiyonu
	string getFileName();
	// Dosyadaki noktalar� nokta bulutu olarak d�nd�ren fonksiyon
	PointCloud capture();
	// Dosyadaki noktalar� nokta bulutuna cevirip transform yapan fonksiyon
	PointCloud captureFor();
};