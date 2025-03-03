/**
* @file		: TransformTest.h
* @Author	: Berna ÇAKIR, Hilal BAYRAMOGLU, Selay YIRTIMCI , Yakup YUCE
* @date		: 05.01.2023
*/
#pragma once
#include "Point.h"
#include "PointCloud.h"
#include <Eigen/Dense>

//Transform sinifi
class Transform
{
private:
	Eigen::Vector3d angles; // stores the rotation angles
	Eigen::Vector3d trans; //stores the distance between origins of coordinate axis
	Eigen::Matrix4d transMatrix; // stores translation matrix values
	Eigen::Matrix3d rotationMatrix; // stores rotation matrix values
	int count;
public:
	//Transform constructor
	Transform();

	//Transform destructor
	~Transform();

	//assign new values
	void set_angles(double, double, double);

	//assign new values 
	void set_trans(double, double, double);

	//assign new values to angles with array
	void setRotation(const Eigen::Vector3d&);

	//assign new values to trans with array
	void setTranslation(const Eigen::Vector3d&);

	//returns trans 
	Eigen::Vector3d get_trans() const;

	//returns angles 
	Eigen::Vector3d get_angles() const;

	//transform fonctions
	Point doTransform(Point p);
	list<Point> doTransform(list<Point>&);
	PointCloud doTransform(PointCloud& pc);
};