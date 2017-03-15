#include "Load.h"
#include "Core.h"

Core::Loading::Loading(Core* core)
{
	_core = core;

	_core->setInput(&cv::imread(_core->getPath()));
}

Core::Loading::~Loading()
{
}

bool Core::Loading::loadNewFrame()
{
	if (_core->getPath() == "")
	{
		printf("File path is not specified!\n");
		return false;
	}

	_core->setInput(&cv::imread(_core->getPath()));
	
	return false;
}

bool Core::Loading::checkIfImageIsValid(cv::Mat * img)
{
	if (img->rows == 0 || img->cols == 0)
		return true;

	return false;
}
