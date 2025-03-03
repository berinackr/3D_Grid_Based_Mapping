/**
* @file :    PointCloudRecorder.cpp
* @author :  Hilal Bayramoglu
* @date :    Ocak 2023
* @brief :   Nokta bulutlarini dosyaya yazmaya yarayan fonksiyondur.

*/
#include "PointCloudRecorder.h"
#include "Point.h"
#include <fstream>


/**
* @brief : Yapici fonksiyon
* @param : Dosya adi.
*/
PointCloudRecorder::PointCloudRecorder()
{
}


/**
* @brief : Kaydedilecek dosya adini gosterir.
* @return: Dosya adini dondurur.
*/
string PointCloudRecorder::getFileName()
{
	return fileName;
}


/**
* @brief : Kaydedilecek dosya adini duzenler.
* @param : Kaydedilecek dosya adi.
*/
void PointCloudRecorder::setFileName(string fileName)
{
	this->fileName = fileName;
}


/**
* @brief : Nokta bulutlarini dosyaya yazdirir.
* @param : Nokta bulutu.
* @return : true , false dondurur.
*/
bool PointCloudRecorder::save(const PointCloud& pc)
{
	int count = 0;
	fstream file;
	list<Point>* P = new list<Point>;
	*P = pc.GetPoints();
	file.open(fileName);
	list<Point>::iterator iter;
	if (file.is_open())
	{
		if (fileName != "fNameDeneme.txt") {
			cout << "Dosya acildi." << endl;
			cout << "Kaydediliyor..." << endl << endl;
		}

		for (iter = P->begin(); iter != P->end(); iter++)
		{
			file << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
			count++;
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Dosya acilamadi!" << endl;
	}

	return false;
}