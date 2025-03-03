/**
* @file		: TransformTest.cpp
* @Author	: Berna ÇAKIR, Hilal BAYRAMOGLU, Selay YIRTIMCI , Yakup YUCE
* @date		: 05.01.2023
*/

#include "Transform.h"
#include <math.h>
#include<iostream>
using namespace std;

/**
*	@brief	:	Constructor fonksiyonu.
*/
Transform::Transform() {

}


/**
*	@brief	:	Destructor fonksiyonu.
*/
Transform::~Transform() {

}


/**
*	@brief			      :	Verilen aci degerlerini ang degiskenine uygular.
*	@param	first_angle	  :	Birinci aci.
*	@param	second_angle  :	Ikinci aci.
*	@param	third_angle	  :	Ucuncu aci.
*/
void Transform::set_angles(double first_angle, double second_angle,  double third_angle)
{
	using namespace Eigen;
	this->angles(0) = first_angle;
	this->angles(1) = second_angle;
	this->angles(2) = third_angle;
}


/**
*	@brief : Transform nesnesi icin trans dizisi icerisine koordinant sisteminin orijininin base koordinant
*			sisteminin orijinine olan uzakligini düzenler.
*	@param	transX	:	Birinci deger.
*	@param	transY	:	Ikinci deger.
*	@param	transZ	:	Ucuncu deger.
**/
void Transform::set_trans(double transX, double transY, double transZ)
{
	using namespace Eigen;
	this->trans(0) = transX;
	this->trans(1) = transY;
	this->trans(2) = transZ;
}


/**
*	@brief			:	Acilari elde ettigimiz fonksiyon.
*	@return			:	Aci verileri.
*/
Eigen::Vector3d Transform::get_angles() const
{
	return this->angles;
}


/**
*	@brief			:	Trans dizimizdeki x y z degerini elde ettigimiz fonksiyon.
*	@return			:	Trans vectoru.
*/
Eigen::Vector3d Transform::get_trans() const
{
	return this->trans;
}


/**
*	@brief			:	Ýcine aldigi acilarla vector icin rotasyon matrisini olusturur.
*	@param	ang	    :	Acilarin icerisinde oldugu vector.
*/
void Transform::setRotation(const Eigen::Vector3d& ang)
{
	rotationMatrix(0, 0) = cos(ang(2)) * cos(ang(1));
	rotationMatrix(0, 1) = (cos(ang(2)) * sin(ang(1)) * sin(ang(0))) - (sin(ang(2)) * cos(ang(0)));
	rotationMatrix(0, 2) = (cos(ang(2)) * sin(ang(1)) * cos(ang(0))) + (sin(ang(2)) * sin(ang(0)));
	rotationMatrix(1, 0) = sin(ang(2)) * cos(ang(1));
	rotationMatrix(1, 1) = (sin(ang(2)) * sin(ang(1)) * sin(ang(0))) + (cos(ang(2)) * cos(ang(0)));
	rotationMatrix(1, 2) = (sin(ang(2)) * sin(ang(1)) * cos(ang(0))) - (cos(ang(2)) * sin(ang(0)));
	rotationMatrix(2, 0) = -sin(ang(1));
	rotationMatrix(2, 1) = cos(ang(1)) * sin(ang(0));
	rotationMatrix(2, 2) = cos(ang(1)) * cos(ang(0));
}


/**
*	@brief : Rotasyon aci degerlerini trans matrisine uygular.
*	@param Trans x, y, z degerlerinin icerisinde oldugu vector.
*/
void Transform::setTranslation(const Eigen::Vector3d& tr)
{
	using namespace Eigen;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix(x, y) = rotationMatrix(x, y);
		}
	}
	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	this->transMatrix(0, 3) = tr(0);
	this->transMatrix(1, 3) = tr(1);
	this->transMatrix(2, 3) = tr(2);
}


/**
*	@brief			:	Bu fonksiyon bir Pointlist alarak onu base koordinant sistemine gore x,y,z degerlerini donusturur.
*	@param	listp	:	Donusturulme islemi yapilacak Pointlist.
*	@return			:	Donusturulmus Pointlist.
*/
list<Point> Transform::doTransform(list<Point>& listp)
{
	list<Point>* TransformedL = new list<Point>;
	list<Point>::iterator iter;

	for (iter = listp.begin(); iter != listp.end(); iter++)
	{
		TransformedL->push_back(doTransform(*iter));
	}
	return *TransformedL;
}


/**
*	@brief			:	Bu fonksiyon bir Point alarak bu Pointi base koordinant sistemine gore x,y,z degerlerini donusturur.
*	@param	p		:	Donusturulme islemi yapilacak Point.
*	@return			:	Donusturulmus Point.
*/
Point Transform::doTransform(Point p)
{
	Point* Transpoint = new Point;
	double sum = 0;
	Eigen::MatrixXf result(4, 1), point(4, 1);
	point(0, 0) = float(p.getX());
	point(1, 0) = float(p.getY());
	point(2, 0) = float(p.getZ());
	point(3, 0) = 1;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < 4; k++) {
				sum += (transMatrix(i, k) * point(k, j));
			}
			result(i, j) = float(sum);
			sum = 0;
		}
	}

	Transpoint->setX(result(0, 0));
	Transpoint->setY(result(1, 0));
	Transpoint->setZ(result(2, 0));

	return *Transpoint;
}


/**
*	 @brief    :    Ýcine aldigi PointCloud tan olusturulmus bir nokta bulutunu alip transform islemine tabi tutar ve PointCloud tipinde dondurur.
*	 @param pc :    Donusturulucek nokta bulutudur.
*	 @return   :	Donusturulmus PointCloud.
*/
PointCloud Transform::doTransform(PointCloud& pc)
{
	PointCloud* TransPointCloud = new PointCloud(0);
	list<Point> p;
	p = pc.GetPoints();
	p = doTransform(p);

	TransPointCloud->SetPoints(p);
	TransPointCloud->SetPointNumber(p.size());

	return *TransPointCloud;
}