#pragma once

#include "Core.h"

namespace VisionCore
{
	class Core;
	
	class Loading
	{
	public:
		Loading();
		Loading(Core* core);
		~Loading();

		bool loadNewFrame();

	private:
		/* Funtions */
		bool checkIfImageIsValid(cv::Mat* img);

		Core* _core;
	};
}
