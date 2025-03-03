/**
* @file   PointCloudRecorder.h
* @Author : Hilal Bayramoglu
* @date : Ocak 2023
* @brief : Nokta bulutundaki noktalar FName.txt dosyasýna kaydedilir.
*/

#include "Point.h"
#include "PointCloud.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;
class PointCloudRecorder
{
private:
	string fileName;
public:
	//!Yapici fonksiyon.
	PointCloudRecorder();
	//!Dosya adini gonderir.
	string getFileName();
	//! Dosya adini belirler.
	void setFileName(string);
	//!Dosyaya noktalari kaydeder.
	bool save(const PointCloud&);
};
