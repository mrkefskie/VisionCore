#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <opencv2\opencv.hpp>

#include "Load.h"

namespace Core
{
	class Core
	{
	public:
		//TODO: create support for photo files
		//TODO: create support for video files
		//TODO: create support for live video
		//TODO: create support for live images
		Core(char* path);
		~Core();

		bool load();

		cv::Mat getImage();

		char* getPath() { return _path; }
		
		cv::Mat setInput(cv::Mat* input) { _input = input; }
		cv::Mat setOutput(cv::Mat* output) { _output = output; }

	private:
		/* FUNCTIONS */


		/* VARIABLES */
		char* _path;
		cv::Mat _image;

		cv::Mat* _input;
		cv::Mat* _output;

		Loading* _loading;

		//Loading* _loading;
	};
}