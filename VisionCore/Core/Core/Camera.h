#pragma once

#include "Core.h"

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	class Core;

	class Camera
	{
	public:
		Camera(Core* core, int id);
		~Camera();

		bool StartCamera();

		bool getNewFrameWithPolling();

		void setID(int id) { _camID = id; }
		int getID() { return _camID; }
	private:
		Core* _core;

		int _camID;

		cv::VideoCapture* _videoCap;
	};
}
