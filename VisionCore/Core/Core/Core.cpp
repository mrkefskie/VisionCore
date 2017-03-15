#include "Core.h"
#include "Load.h"

#include <opencv2\opencv.hpp>

Core::Core::Core(char * path)
{
	_path = path;

	_image = NULL;

	_loading = new Loading(this);
}

Core::Core::~Core()
{
}

bool Core::Core::load()
{
	return _loading->loadNewFrame();
}

cv::Mat Core::Core::getImage()
{
	if (_image.rows == 0 || _image.cols == 0)
		return cv::Mat(1, 1, 0);

	return _image;
}

