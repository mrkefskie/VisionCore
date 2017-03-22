#include "Load.h"
#include "Core.h"

VisionCore::Loading::Loading()
{
}

VisionCore::Loading::Loading(Core* core, bool photo)
{
	_core = core;

	_photo = photo;

	if (_photo == false)
	{
		char* path = _core->getPath();
		if (path == "")
		{
			printf("File path is not specified!\n");
			return;
		}

		_loadVideo = new cv::VideoCapture(path);
		_loadVideo->set(CV_CAP_PROP_FPS, 30);
	}

	//_core->setInput(cv::imread(_core->getPath()));
}

VisionCore::Loading::~Loading()
{
}

bool VisionCore::Loading::getNewImage()
{
	if (_photo)
	{
		char* path = _core->getPath();

		if (path == "")
		{
			printf("File path is not specified!\n");
			return false;
		}

		cv::Mat img = cv::imread(_core->getPath());

		_core->setInput(img);
	}
	else
	{
		cv::Mat img;

		//success = _loadVideo->read(img);

		_loadVideo->operator>>(img);

		_core->setInput(img);
	}
	return true;
}

bool VisionCore::Loading::checkIfImageIsValid(cv::Mat * img)
{
	if (img->rows == 0 || img->cols == 0)
		return true;

	return false;
}
