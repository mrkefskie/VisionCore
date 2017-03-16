#include "Camera.h"

VisionCore::Camera::Camera(int id)
{
	_camID = id;
}

VisionCore::Camera::~Camera()
{
}

bool VisionCore::Camera::StartCamera()
{
	_videoCap = new cv::VideoCapture(_camID);

	if (!_videoCap->isOpened())
		return false;

	return true;
}
