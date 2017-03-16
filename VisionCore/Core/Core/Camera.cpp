#include "Camera.h"

VisionCore::Camera::Camera(Core* core, int id)
{
	_core = core;

	_camID = id;
}

VisionCore::Camera::~Camera()
{
}

bool VisionCore::Camera::StartCamera()
{
	_videoCap = new cv::VideoCapture(_camID);

	_videoCap->set(cv::CAP_PROP_FRAME_WIDTH, 1600);
	_videoCap->set(cv::CAP_PROP_FRAME_HEIGHT, 900);
	_videoCap->set(cv::CAP_PROP_FPS, 60);

	if (!_videoCap->isOpened())
		return false;

	return true;
}

bool VisionCore::Camera::getNewFrameWithPolling()
{
	cv::Mat img;
	
	bool success = _videoCap->read(img);
	if (!success)
		return false;

	_core->setInput(img);

	return true;
}
