#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <opencv2\opencv.hpp>

#include "Load.h"
#include "Camera.h"

namespace VisionCore
{
	class Loading;
	class Camera;

	class Core
	{
	public:
		//TODO: create support for video files
		//TODO: create support for live video
		//TODO: create support for live images
		Core(char* path);
		Core(int cameraID);

		~Core();

		bool load();

		cv::Mat getImage();
		cv::Mat getInput();
		cv::Mat getOutput();


		char* getPath() { return _path; }
		
		void setInput(cv::Mat input) { _input = input; }
		void setOutput(cv::Mat output) { _output = output; }
		 
	private:
		/* FUNCTIONS */


		/* VARIABLES */
		int _frameLocation;

		char* _path;
		cv::Mat _image;

		cv::Mat _input;
		cv::Mat _output;

		Loading* _loading = nullptr;
		Camera* _camera = nullptr;

		int _camID;
	};
}