#include "Load.h"
#include "Core.h"

VisionCore::Loading::Loading(Core* core)
{
	_core = core;

	//_core->setInput(cv::imread(_core->getPath()));
}

VisionCore::Loading::~Loading()
{
}

bool VisionCore::Loading::loadNewFrame()
{
	char* path = _core->getPath();

	if (path == "")
	{
		printf("File path is not specified!\n");
		return false;
	}

	cv::Mat img = cv::imread(_core->getPath());

	_core->setInput(img);
	
	return true;
}

bool VisionCore::Loading::checkIfImageIsValid(cv::Mat * img)
{
	if (img->rows == 0 || img->cols == 0)
		return true;

	return false;
}
