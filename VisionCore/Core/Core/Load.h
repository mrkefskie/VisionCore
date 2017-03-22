#pragma once

#include "Core.h"

namespace VisionCore
{
	class Core;
	
	class Loading
	{
	public:
		Loading();
		Loading(Core* core, bool photo);
		~Loading();

		bool getNewImage();

	private:
		/* Funtions */
		bool checkIfImageIsValid(cv::Mat* img);

		bool _photo;

		cv::VideoCapture* _loadVideo;

		Core* _core;
	};
}
