#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

#include <opencv2\opencv.hpp>

#include "Load.h"
#include "Camera.h"
#include "VCStruct\CameraData.h"

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
		Core(int cameraID, VisionCore::VCStruct::VideoSettings settings);

		~Core();

		bool load();

		bool run();

		cv::Mat getImage();
		cv::Mat getInput();
		cv::Mat getOutput();

		bool saveVideoToHDD() { return _saveVideoToHDD; }

		char* getPath() { return _path; }
		VisionCore::VCStruct::VideoSettings* getVideoSettings() { return _videoSettings; }

		void setInput(cv::Mat input) { _input = input; }
		void setOutput(cv::Mat output) { _output = output; }
		 
		void setSaveVideoToHDD(bool val);

	private:
		/* FUNCTIONS */


		/* VARIABLES */

		// Times for FPS calculation
#ifdef _WINDOWS_
		LARGE_INTEGER PreviousTime, CurrentTime, ElapsedMicroSeconds;
		LARGE_INTEGER Frequency;

		double inv_FPS;
		double FPS;
#endif

		bool _isCameraConnected;
		bool _saveVideoToHDD;

		int _frameLocation;

		char* _path;
		cv::Mat _image;

		cv::Mat _input;
		cv::Mat _output;

		Loading* _loading;
		Camera* _camera;

		int _camID;
		VisionCore::VCStruct::VideoSettings* _videoSettings;
	};
}