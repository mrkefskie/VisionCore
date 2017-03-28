#include "VCEnum\Constants.h"

#include "Defines.h"

#include "Core.h"
#include "Load.h"

#include <opencv2\opencv.hpp>

VisionCore::Core::Core(char * path)
{
#ifdef _WINDOWS_
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&PreviousTime);
	QueryPerformanceCounter(&CurrentTime);
#endif
	_path = path;

	_image = NULL;

	_loading = new Loading(this, false);

	_frameLocation = VisionCore::VCEnum::frameLoc::HARDDISK;
}

VisionCore::Core::Core(int cameraID, VisionCore::VCStruct::VideoSettings settings)
{
#ifdef _WINDOWS_
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&PreviousTime);
	QueryPerformanceCounter(&CurrentTime);
#endif

	_videoSettings = &settings;

	_camID = cameraID;

	_camera = new Camera(this, cameraID);

	_frameLocation = VisionCore::VCEnum::frameLoc::CAMERA;

	_isCameraConnected = _camera->StartCamera();
	_saveVideoToHDD = false;

	if (!_isCameraConnected)
	{
		printf("Initialisation of camera failed!\n");
		printf("Shutting down the application.\n");
	}
}

VisionCore::Core::~Core()
{
	delete(_camera);
	delete(_loading);

	printf("Shutting down the VisionCore\n");
}

void VisionCore::Core::addOperator(VisionCore::VCEnum::Operation operatorType)
{
#ifdef DEBUG
	printf("Adding operation of type: %d\n", operatorType);
	printf("Operators: %d\n", _operators.size());
#endif
	_operators.push_back(operatorType);


	switch (operatorType)
	{
	case VisionCore::VCEnum::Operation::FILTER_GAUSSIAN_BLUR:
	{
		_gaussianBlurs.push_back(VisionCore::Blurs::Gaussian(cv::Size(11, 11), 11, 11));
		_gaussianBlurCount++;
	}
	break;
	case VisionCore::VCEnum::Operation::FILTER_AVERAGE:
	{
		_averageBlurs.push_back(VisionCore::Blurs::Average(cv::Size(21, 21)));
		_averageBlurCount++;
	}
	break;
	case VisionCore::VCEnum::Operation::FILTER_MEDIAN_BLUR:
	{
		_medianBlurs.push_back(VisionCore::Blurs::Median(21));
		_medianBlurCount++;
	}
	break;
	case VisionCore::VCEnum::Operation::FILTER_BILATERLAL:
	{
		_bilateralBlurs.push_back(VisionCore::Blurs::Bilateral(3, 1, 1));
		_bilateralBlurCount++;
	}
	break;
	default:
		printf("Dafuq?\n");
		break;
	}
}

bool VisionCore::Core::load()
{
	try
	{
		return _loading->getNewImage();
	}
	catch (std::exception&)
	{
		return false;
	}
}

bool VisionCore::Core::run()
{
	switch (_frameLocation)
	{
	case VisionCore::VCEnum::frameLoc::CAMERA:
	{
		while (1)
		{
			if (!_isCameraConnected)
			{
				printf("The camera is not initialised or ready to be used!\n");
				return false;
			}

			_camera->getNewFrameWithPolling();

			int gaussianBlurCurrentCount = 0;
			int averageBlurCurrentCount = 0;
			int medianBlurCurrentCount = 0;
			int bilateralBlurCurrentCount = 0;

			// Do the processing
			for (int i = 0; i < _operators.size(); i++)
			{
				switch (_operators[i])
				{
				case VisionCore::VCEnum::Operation::FILTER_GAUSSIAN_BLUR:
					_output = _gaussianBlurs[gaussianBlurCurrentCount++].proccessImage(_input);
					break;
				case VisionCore::VCEnum::Operation::FILTER_AVERAGE:
					_output = _averageBlurs[averageBlurCurrentCount++].processImage(_input);
					break;
				case VisionCore::VCEnum::Operation::FILTER_MEDIAN_BLUR:
					_output = _medianBlurs[medianBlurCurrentCount++].processImage(_input);
					break;
				case VisionCore::VCEnum::Operation::FILTER_BILATERLAL:
					_output = _bilateralBlurs[bilateralBlurCurrentCount++].processImage(_input);
					break;
				default:
					printf("This should never happen!\n");
					break;
				}
			}

			if (_saveVideoToHDD)
				_camera->saveVideo(&_input);

#ifdef _WINDOWS_
			QueryPerformanceCounter(&CurrentTime);

			ElapsedMicroSeconds.QuadPart = CurrentTime.QuadPart - PreviousTime.QuadPart;

			ElapsedMicroSeconds.QuadPart *= 1000000;
			ElapsedMicroSeconds.QuadPart /= Frequency.QuadPart;

			inv_FPS = ElapsedMicroSeconds.QuadPart / 1000000.f;

			FPS = 1 / inv_FPS;

			//printf("ElapsedSeconds: %f\tFPS: %f\n", inv_FPS, FPS);
			
			PreviousTime.QuadPart = CurrentTime.QuadPart;

			std::stringstream ss;
			ss << FPS << " fps";

			cv::putText(_input, ss.str(), cv::Point(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(200, 200, 250));
#endif

			cv::imshow("live feed", _input);
			if (_output.rows != 0 || _output.cols != 0)
				cv::imshow("Blurred image", _output);

			if (cv::waitKey(30) >= 0) return true;
		}
	}
	break;
	case VisionCore::VCEnum::frameLoc::HARDDISK:
	{
		while (1)
		{
			int gaussianCurrentCount = 0;


			// Get the frame
			_loading->getNewImage();

			if (_input.empty())
			{
				printf("End of file reached!\n");
				return true;
			}

			// Do the processing
			for (int i = 0; i < _operators.size(); i++)
			{
				switch (_operators[i])
				{
				case VisionCore::VCEnum::Operation::FILTER_GAUSSIAN_BLUR:
					_output = _gaussianBlurs[gaussianCurrentCount++].proccessImage(_input);
				break;

				}
			}

#ifdef _WINDOWS_
			QueryPerformanceCounter(&CurrentTime);

			ElapsedMicroSeconds.QuadPart = CurrentTime.QuadPart - PreviousTime.QuadPart;

			ElapsedMicroSeconds.QuadPart *= 1000000;
			ElapsedMicroSeconds.QuadPart /= Frequency.QuadPart;

			inv_FPS = ElapsedMicroSeconds.QuadPart / 1000000.f;

			FPS = 1 / inv_FPS;

			//printf("ElapsedSeconds: %f\tFPS: %f\n", inv_FPS, FPS);

			PreviousTime.QuadPart = CurrentTime.QuadPart;

			std::stringstream ss;
			ss << FPS << " fps";

			cv::putText(_input, ss.str(), cv::Point(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(200, 200, 250));
#endif

			cv::imshow("video", _input);

			if (cv::waitKey(30) >= 0) return true;
		}
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

void VisionCore::Core::setSaveVideoToHDD(bool val)
{
	_saveVideoToHDD = val;
	_camera->openVideoWriter();
}

