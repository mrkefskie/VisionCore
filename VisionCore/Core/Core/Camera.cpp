#include "Camera.h"

VisionCore::Camera::Camera()
{
}

VisionCore::Camera::Camera(Core* core, int id)
{
	_core = core;

	_camID = id;
}

VisionCore::Camera::~Camera()
{
	_videoWriter->release();
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

void VisionCore::Camera::saveVideo(cv::Mat* frame)
{
	if (_core->saveVideoToHDD() == true)
	{
		if (!_videoWriter->isOpened())
			openVideoWriter();
		else
			_videoWriter->write(*frame);
	}
}

void VisionCore::Camera::openVideoWriter()
{
	int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
	cv::Size S = cv::Size((int)_videoCap->get(CV_CAP_PROP_FRAME_WIDTH), (int)_videoCap->get(CV_CAP_PROP_FRAME_HEIGHT));

	int fps = _core->getVideoSettings()->fps;

	printf("Size (W: %d, H:%d)\n", S.width, S.height);
	printf("FPS: %d\n", fps);


	_videoWriter = new cv::VideoWriter("video.avi", codec, fps, S, true);

	_isVideoWriterOpen = _videoWriter->open("video.avi", codec, fps, S, true);

	if (!_videoWriter->isOpened())
	{
		printf("Could not open the output video for write\n");
	}
}
