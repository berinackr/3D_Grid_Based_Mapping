#include "MapperInterface.h";

MapperInterface::MapperInterface():map(NULL),recorder(NULL),pointCloud(0),patch(0)
{

}
MapperInterface::~MapperInterface()
{
	int i;
	for (i = 0; i < generators.size(); i++) {
		delete generators.at(i);
	}
	delete recorder;
	//delete map;
}
void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
	generators.push_back(generator);
}

void MapperInterface::setRecorder(PointCloudRecorder* recorder)
{
	this->recorder = recorder;
}

bool MapperInterface::generate()
{
	int i;

	for (i = 0; i < generators.size(); i++) {
		patch = generators.at(i)->captureFor();
		pointCloud = pointCloud + patch;
	}

	return true;
}

bool MapperInterface::recordPointCloud()
{
	if (recorder != NULL) {
		recorder->save(pointCloud);
		return true;
	}
	else {
		return false;
	}
}

bool MapperInterface::recordMap() {

	if (map != NULL) {
		map->saveMap("SaveMap.txt");
		return true;
	}
	else {
		return false;
	}
	return true;
}


bool MapperInterface::insertMap()
{
	map->insertPointCloud(pointCloud);
	return true;
}

