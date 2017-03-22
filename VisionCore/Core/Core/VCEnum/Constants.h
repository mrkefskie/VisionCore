#pragma once

namespace VisionCore
{
	namespace VCEnum
	{
		enum frameLoc
		{
			HARDDISK,
			CAMERA
		};

		enum Operation
		{
			FILTER_AVERAGE,
			FILTER_GAUSSIAN_BLUR,
			FILTER_MEDIAN_BLUR,
			FILTER_BILATERLAL
		};
	}
}
