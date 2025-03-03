#include"PointCloudGenerator.h"

PointCloudGenerator::PointCloudGenerator(){

}
PointCloudGenerator::~PointCloudGenerator(){

}
void PointCloudGenerator::setTransform(const Transform& t)
{
	this->transform = t;
}
Transform PointCloudGenerator::getTransform() const
{
	return this->transform;
}