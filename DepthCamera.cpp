/**
* @file		: DepthCamera.cpp
* @Author	: Berna ÇAKIR
* @date		: 05.01.2023
*/

#include <fstream>
#include "DepthCamera.h"
#include "Point.h"
#include"Transform.h"
#include "PointCloud.h"
#include "DepthCamera.h"

using namespace std;

/**
* @brief	 : Constructor fonksiyonu.
*/
DepthCamera::DepthCamera(string _fileName = " ")
{
	setFileName(_fileName);
}


/**
* @brief	 : Destructor fonksiyonu.
*/
DepthCamera::~DepthCamera(){ 
}


/**
* @brief	 : DepthCamera sinifinin icerisindeki fileName degiskenine atama islemi yapmamizi saglar.
* @param	 : Icerisine string tipinde bir parametre alir.
*/
void DepthCamera::setFileName(string fileName)
{
	this->fileName = fileName;
}


/**
* @brief	 : DepthCamera sinifinin icerisindeki fileName degiskenini dondurur.
*/
string DepthCamera::getFileName()
{
	return this->fileName;
}


/**
* @brief	 : Camera dosyalarinin icerisindeki noktalari okur ve bir Pointcloud icerisine atar. PointCloud nesnesini dondurur.
*/
PointCloud DepthCamera::capture()
{
	int rgb; // rgbleri okumasi icin tanimlanmis degisken
	Point p;
	
	ifstream file(getFileName());
	int count = 0;
	double x, y, z;
	list<Point>* point_list = new list<Point>;
	PointCloud pc(0);

	if (!file)
	{
		cout << this->getFileName() <<" dosyasi acilamadi" << endl;
		exit(0);
	}
	else
	{
		// dosya satirlarindaki noktalari listeye ekler
		while (file)
		{
			file >> x;
			p.setX(x);
			file >> y;
			p.setY(y);
			file >> z;
			p.setZ(z);
			point_list->push_back(p);

			//rgbleri atlama dongusu
			for (int i = 0; i < 3; i++)
			{
				file >> rgb;
			}
			count++;
		}

		file.close();
		pc.SetPointNumber(count - 1);
		pc.SetPoints(*point_list);

	}

	//nokta bulutu dondurur
	return pc;
}


/**
* @brief	 : Camera dosyalarinin icerisindeki noktalari capture ile okur ve transform ederek PointCloud nesnesini dondurur.
*/
PointCloud DepthCamera::captureFor()
{
	// PointCloud nesnesine dosyadaki pointleri capture fonksiyonu ile atar 
	PointCloud pc(0);
	pc = this->capture();

	Transform T;

	//cam.txt dosyasi icin
	if (fileName == "cam.txt") {

		T.set_trans(1.95704, 1.93000, 1.05707);
		T.set_angles(-1.5800005571355884, -0.0072950557, 2.3568993342957150);
		T.setRotation(T.get_angles());
		T.setTranslation(T.get_trans());

	}

	//cam1.txt dosyasi icin
	if (fileName == "cam1.txt")
	{
		T.set_trans(-1.91288, 1.94412, 1.05465);
		T.set_angles(-90.5273381, -0.00182376393, -2.2967332126651585);
		T.setRotation(T.get_angles());
		T.setTranslation(T.get_trans());
	}

	//cam2.txt dosyasi icin
	if (fileName == "cam2.txt")
	{
		T.set_trans(1.96978, -1.94622, 1.05264);
		T.set_angles(-1.5799994562618263, -0.00091188196, 0.50283882984821737);
		T.setRotation(T.get_angles());
		T.setTranslation(T.get_trans());
	}
	
	//cam3.txt dosyasi icin
	if (fileName == "cam3.txt")
	{

		T.set_trans(-1.87445, -1.95027, 1.06432);
		T.set_angles(-1.5799997571694364, -0.00273564589, -1.2028443985607811);
		T.setRotation(T.get_angles());
		T.setTranslation(T.get_trans());
	}

	//nokta bulutunu transform yapar
	pc = T.doTransform(pc);

	//nokta bulutu dondurur
	return pc;
}