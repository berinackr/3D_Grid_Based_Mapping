#pragma once
#include <vector>
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"
#include "Map.h"
#include <list>

class MapperInterface{
private:

	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;

public:
	MapperInterface();
	~MapperInterface();
	void addGenerator(PointCloudGenerator* generator);
	void setRecorder(PointCloudRecorder* recorder);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
};
