/**
* @file		: ThreeDGridMap.cpp
* @Author	: Berna ÇAKIR, Hilal BAYRAMOGLU, Selay YIRTIMCI , Yakup YUCE
* @date		: 05.01.2023
*/

#include "ThreeDGridMap.h"

/**
* @brief	 : Constructor fonksiyonu.
* @param	 : Icerisine int ve float tipinde bir parametre alir.
*/
ThreeDGridMap::ThreeDGridMap(int depth = 100, float gridSize = 10) : depth(depth), gridSize(gridSize) {

    // Tüm küplerin deðerini false yapar
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                map[i][j][k] = false;
            }
        }
    }
}


/**
* @brief	 : Destructor fonksiyonu.
*/
ThreeDGridMap::~ThreeDGridMap() {};


/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki depth degiskenine atama islemi yapmamizi saglar.
* @param	 : Icerisine int tipinde bir parametre alir.
*/
void ThreeDGridMap::setDepth(int depth)
{
    this->depth = depth;
};


/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki depth degiskenini dondurur.
*/
int ThreeDGridMap::getDepth() {
    return this->depth;
};


/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki gridSize degiskenine atama islemi yapmamizi saglar.
* @param	 : Icerisine float tipinde bir parametre alir.
*/
void ThreeDGridMap::setGridSize(float gridSize) {
    this->gridSize = gridSize;
};


/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki gridSize degiskenini dondurur.
*/
float ThreeDGridMap::getGridSize() {
    return this->gridSize;
};


/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki map icine verilen pointcloudları doldurur
* @param	 : Icerisine Point tipinde bir parametre alir.
*/
void ThreeDGridMap::insertPointCloud(PointCloud& pc) {
    list<Point> listp = pc.GetPoints();
    list<Point>::iterator iter;
    Point p;

    for (iter = listp.begin(); iter != listp.end(); iter++) {
        insertPoint((*iter));
    }
}

/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki map icine verilen pointi doldurur
* @param	 : Icerisine Point tipinde bir parametre alir.
*/
void ThreeDGridMap::insertPoint(Point& p) {

    int i = p.getX() / gridSize;
    int j = p.getY() / gridSize;
    int k = p.getZ() / gridSize;
    map[i][j][k] = true;
}


/**
* @brief	 : ThreeDGridMap sinifinin icerisindeki verilen noktanın dolu olup olmadigini dondurur
*/
bool ThreeDGridMap::getGrid(int x, int y, int z) {
    if (map[x][y][z] == true)
        return true;
    else
        return false;
}

bool ThreeDGridMap::loadMap(string fileName) {
    fstream file;
    Point p;
    double x, y, z;

    file.open(fileName);

    if (!file)
    {
        return false;
    }
    else
    {
        while (file)
        {
            file >> x;
            p.setX(x);
            file >> y;
            p.setY(y);
            file >> z;
            p.setZ(z);

            (*this).insertPoint(p);

        }
        return true;
    }
}
bool ThreeDGridMap::saveMap(string fileName) {
    fstream file;

    file.open(fileName);


    if (!file) {
        return false;
    }

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                file << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
    return true;

}