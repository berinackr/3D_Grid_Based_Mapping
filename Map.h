#pragma once
#include <iostream>
#include "Point.h"
#include "PointCloud.h"
#include <vector>
using namespace std;
class Map
{
private:
    vector<PointCloud> pointClouds;

public:
    Map();
    ~Map();
    virtual void insertPointCloud(PointCloud& pc) = 0;
    virtual void insertPoint(Point& p) = 0;
    virtual bool loadMap(string fileName) = 0;
    virtual bool saveMap(string fileName) = 0;
};
