#pragma once

#include "Core.h"

namespace Core
{
	class Core;
	
	class Loading
	{
	public:
		Loading(Core* core);
		~Loading();

		bool loadNewFrame();

	private:
		/* Funtions */
		bool checkIfImageIsValid(cv::Mat* img);

		Core* _core;
	};
}
