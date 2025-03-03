/**
* @file		: Point.cpp
* @Author	: Yakup Yuce (y4kupyuce@gmail.com)
* @date		: Ocak 2023
*/

#include "Point.h"

using namespace std;

/*Kurucu fonksiyon x,y ve z degerlerini default olarak atar*/
Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}

/*Yikici fonksiyon*/
Point::~Point() {

}

/*@Brief		:X koordinatini atamayý saglar. Deger dödürmez.
@Param			:Double bir ifade alir*/
void Point::setX(const double x) {
	this->x = x;
}
/*@Brief		:Y koordinatini atamayý saglar.Deger dödürmez.
@Param			:Double bir ifade alir*/
void Point::setY(const double y) {
	this->y = y;
}

/*@Brief		:Z koordinatini atamayý saglar. Deger dödürmez.
@Param			:Double bir ifade alir*/
void Point::setZ(const double z) {
	this->z = z;
}

/*@Brief		:Noktanin X koordinatini cagirma fonksiyonu.
X'in koordinatin double bir sekilede dödürür.
@Param			:Bir deger almaz  */
double Point::getX() const {
	return this->x;
}

/*@Brief		:Noktanin Y koordinatini cagirma fonksiyonu.
Y'in koordinatin double bir sekilede dödürür.
@Param			:Bir deger almaz  */
double Point::getY() const {
	return this->y;
}

/*@Brief		:Noktanin Z koordinatini cagirma fonksiyonu.
Z'in koordinatin double bir sekilede dödürür.
@Param			:Bir deger almaz  */
double Point::getZ() const {
	return this->z;
}

/*@Brief			:" == "   operatoru ile iki noktanin esitligini sorgular.
Bool bir ifade dödürür.
@Param				:Bir nokta nesnesi alir */
bool Point::operator==(const Point& point) const
{
	return (this->x == point.x && this->y == point.y && this->z == point.z);
}

/*@Brief		 :Nokta arasi uzaklik hesaplama fonksiyonu.Uzakligi double olarak geri döndürür
@Param			 :Bir point nesnesi alir */
double Point::distance(const Point& point) const
{
	return  (sqrt(pow(point.x - this->x, 2) + pow(point.y - this->y, 2) + pow(point.z - this->z, 2)));
}
