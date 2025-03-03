#include"Transform.h"


class PointCloudGenerator{
private:
	Transform transform;
public:
	PointCloudGenerator();
	~PointCloudGenerator();
	void setTransform(const Transform&);
	Transform getTransform() const;
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};