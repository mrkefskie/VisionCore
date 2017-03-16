#include "VCEnum\Constants.h"

#include "Core.h"
#include "Load.h"

#include <opencv2\opencv.hpp>

VisionCore::Core::Core(char * path)
{
	_path = path;

	_image = NULL;

	_loading = new Loading(this);

	_frameLocation = VisionCore::VCEnum::frameLoc::HARDDISK;
}

VisionCore::Core::Core(int cameraID)
{
	_camID = cameraID;

	_camera = new Camera(this, cameraID);

	_frameLocation = VisionCore::VCEnum::frameLoc::CAMERA;

	_camera->StartCamera();
}

VisionCore::Core::~Core()
{
	delete(_camera);
	delete(_loading);

	printf("Shutting down the VisionCore\n");
}

bool VisionCore::Core::load()
{
	return _loading->loadNewFrame();
}

bool VisionCore::Core::run()
{
	switch (_frameLocation)
	{
	case VisionCore::VCEnum::frameLoc::CAMERA:
	{
		while (1)
		{
			_camera->getNewFrameWithPolling();

			cv::imshow("live feed", _input);

			if (cv::waitKey(30) >= 0) return true;
		}
	}
	break;
	case VisionCore::VCEnum::frameLoc::HARDDISK:
	{
		return false;
	}
	break;
	default:
		break;
	}
}

cv::Mat VisionCore::Core::getImage()
{
	if (_image.rows == 0 || _image.cols == 0)
		return cv::Mat(1, 1, 0);

	return _image;
}

cv::Mat VisionCore::Core::getInput()
{
	if (_input.rows == 0 || _input.cols == 0)
		return cv::Mat(1, 1, 0);

	return _input;
}

cv::Mat VisionCore::Core::getOutput()
{
	if (_output.rows == 0 || _output.cols == 0)
		return cv::Mat(1, 1, 0);

	return _output;
}

