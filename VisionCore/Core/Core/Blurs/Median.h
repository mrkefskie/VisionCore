#pragma once

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	namespace Blurs
	{
		class Median
		{
		public:
			Median(int kSize) { _kSize = kSize; }

			cv::Mat processImage(cv::Mat input)
			{
				cv::Mat output;
				cv::medianBlur(input, output, _kSize);
				return output;
			}

			int getKSize() { return _kSize; }

			void setKSize(int kSize) { _kSize = kSize; }
		private:
			int _kSize;
		};
	}
}