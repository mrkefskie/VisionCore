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

	_videoCap->set(cv::CAP_PROP_FRAME_WIDTH, _core->getVideoSettings()->frame_width);
	_videoCap->set(cv::CAP_PROP_FRAME_HEIGHT, _core->getVideoSettings()->frame_height);
	_videoCap->set(cv::CAP_PROP_FPS, _core->getVideoSettings()->fps);

	if (!_videoCap->isOpened());
		return false;

	return true;
}

bool VisionCore::Camera::getNewFrameWithPolling()
{
	cv::Mat img;
	
	bool success = _videoCap->retrieve(img);
	if (!success)
		return false;

	_core->setInput(img);

	return true;
}
