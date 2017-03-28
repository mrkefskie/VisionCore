#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

#include <opencv2\opencv.hpp>

#include "Load.h"
#include "Camera.h"

#include "Blurs\Gaussian.h"
#include "Blurs\Average.h"
#include "Blurs\Median.h"
#include "Blurs\Bilateral.h"

#include "VCStruct\CameraData.h"
#include "VCEnum\Constants.h"

namespace VisionCore
{
	class Loading;
	class Camera;

	class Core
	{
	public:
		Core(char* path);
		Core(int cameraID, VisionCore::VCStruct::VideoSettings settings);

		~Core();

		void addOperator(VisionCore::VCEnum::Operation operatorType);

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

		// List for all the operations to be done
		std::vector<VisionCore::VCEnum::Operation> _operators;

		std::vector<VisionCore::Blurs::Gaussian> _gaussianBlurs;
		std::vector<VisionCore::Blurs::Average> _averageBlurs;
		std::vector<VisionCore::Blurs::Median> _medianBlurs;
		std::vector<VisionCore::Blurs::Bilateral> _bilateralBlurs;

		int _gaussianBlurCount = 0;
		int _averageBlurCount = 0;
		int _medianBlurCount = 0;
		int _bilateralBlurCount = 0;

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