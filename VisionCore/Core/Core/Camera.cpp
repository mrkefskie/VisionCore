#include "Camera.h"

VisionCore::Camera::Camera(Core* core, int id)
{
	_core = core;

	_camID = id;
}

VisionCore::Camera::~Camera()
{
	_videoCap->release();

	printf("Shutting down the Camera\n");
}

bool VisionCore::Camera::StartCamera()
{
	_videoCap = new cv::VideoCapture(_camID);

	if (!_videoCap->open(_camID))
		return false;

	_videoCap->set(cv::CAP_PROP_FRAME_WIDTH, _core->getVideoSettings()->frame_width);
	_videoCap->set(cv::CAP_PROP_FRAME_HEIGHT, _core->getVideoSettings()->frame_height);
	_videoCap->set(cv::CAP_PROP_FPS, _core->getVideoSettings()->fps);

	if (!_videoCap->isOpened())
		return false;

	return true;
}

bool VisionCore::Camera::getNewFrameWithPolling()
{
	if (!_videoCap->isOpened())
		return false;

	cv::Mat img;
	
	bool success = _videoCap->read(img);
	if (!success)
		return false;

	_core->setInput(img);

	return true;
}
