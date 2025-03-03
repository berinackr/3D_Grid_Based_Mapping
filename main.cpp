#include<iostream>
#include"Point.h"
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Transform.h"
//#include"ThreeDGridMap.h"
//#include"MapperInterface.h"



using namespace std;

int PointTest();
int TestPointCloud();
int DephtCameraTest();
int TransformTest();
int PointCloudRecorderTest();

void main() {
	int result = 0;
	cout << " ### Test Fonksiyonlari ###" << endl << endl;

	result += PointTest();
	result += TestPointCloud();
	result += DephtCameraTest();
	result += TransformTest();
	result += PointCloudRecorderTest();


	//4 point clouds olusturduk
	PointCloud tempPC(0);
	PointCloud tempPC1(0);
	PointCloud tempPC2(0);
	PointCloud tempPC3(0);
	cout << endl << "Cameralardan veriler okunuyor. Lutfen biraz bekleyiniz..." << endl << endl;

	//cameradan noktalarý okur ve nokta bulutu olarak kaydeder ve transform yapar
	DepthCamera c1("cam.txt");
	tempPC = c1.captureFor();
	cout << " cam.txt okundu ve transform edildi. " << endl;

	c1.setFileName("cam1.txt");
	tempPC2 = c1.captureFor();
	cout << " cam1.txt okundu ve transform edildi. " << endl;

	c1.setFileName("cam2.txt");
	tempPC2 = c1.captureFor();
	cout << " cam2.txt okundu ve transform edildi. " << endl;

	c1.setFileName("cam3.txt");
	tempPC3 = c1.captureFor();
	cout << " cam3.txt okundu ve transform edildi. " << endl << endl;

	PointCloud pc(0);
	pc = tempPC;
	pc = pc + tempPC1;
	pc = pc + tempPC2;
	pc = pc + tempPC3;

	PointCloudRecorder point_cloud_recorder;
	point_cloud_recorder.setFileName("fName.txt");
	point_cloud_recorder.save(pc);

	cout << "Program basariyla sonlandirildi. Ciktilar icin fName.txt dosyasini kontrol ediniz." << endl;

	system("pause");
}