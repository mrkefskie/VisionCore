#pragma once

#include "Core.h"

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	class Core;

	class Camera
	{
	public:
		Camera(int id);
		~Camera();

		bool StartCamera();

		void setID(int id) { _camID = id; }
		int getID() { return _camID; }
	private:
		int _camID;

		cv::VideoCapture* _videoCap;
	};
}
