#pragma once

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	namespace Blurs
	{
		class Bilateral
		{
		public:
			Bilateral(int d, double sigmaColor, double sigmaSpace) { init(d, sigmaColor, sigmaSpace, cv::BorderTypes::BORDER_DEFAULT); }
			Bilateral(int d, double sigmaColor, double sigmaSpace, int borderType) { init(d, sigmaColor, sigmaSpace, borderType); }

			cv::Mat processImage(cv::Mat input)
			{
				cv::Mat output;
				cv::bilateralFilter(input, output, _d, _sigmaColor, _sigmaSpace, _borderType);
				return output;
			}

		private:
			void init(int d, double sigmaColor, double sigmaSpace, int borderType)
			{
				_d = d;
				_sigmaColor = sigmaColor;
				_sigmaSpace = sigmaSpace;
				_borderType = borderType;
			}

			int _d;
			double _sigmaColor;
			double _sigmaSpace;
			int _borderType;
		};
	}
}