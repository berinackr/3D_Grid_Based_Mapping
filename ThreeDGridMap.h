#pragma once
#include "Map.h"
#include <list>
#include<fstream>

//ThreeDGridMap sinifi
class ThreeDGridMap : public Map {
private:
	bool map[100][100][100];
	float gridSize;
	int depth;

public:
	//Constructor.
	ThreeDGridMap(int depth, float gridSize);
	// Destructor fonksiyonu
	~ThreeDGridMap();
	//Set-Get Methods
	void setGridSize(float);
	float getGridSize();
	void setDepth(int);
	int getDepth();
	bool getGrid(int x, int y, int z);
	// insert Methods
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	// save and load Methods
	bool loadMap(string fileName);
	bool saveMap(string fileName);
};

