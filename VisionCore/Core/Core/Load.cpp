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

		bool success = false;

		try
		{
			success = _loadVideo->read(img);
		}
		catch (const std::exception&)
		{
			printf("Exception");
			return false;
		}

		if (!success)
			return false;

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
