#pragma once

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	namespace Blurs
	{
		class Gaussian
		{
		public:
			Gaussian(cv::Size kSize, double sigmaX);
			Gaussian(cv::Size kSize, double sigmaX, double sigmaY);
			Gaussian(cv::Size kSize, double sigmaX, double sigmaY, int borderType);
			~Gaussian();

			cv::Mat proccessImages(cv::Mat input);
			
			cv::Size getKSize() { return _kSize; }
			double getSigmaX() { return _sigmaX; }
			double getSigmaY() { return _sigmaY; }
			int getBorderType() { return _borderType; }

			void setKSize(cv::Size kSize) { _kSize = kSize; }
			void setSigmaX(double sigmaX) { _sigmaX = sigmaX; }
			void setSigmaY(double sigmaY) { _sigmaY = sigmaY; }
			void setBorderType(int borderType) { _borderType = borderType; }

		private:
			void init(cv::Size kSize, double sigmaX, double sigmaY, int borderType);

			cv::Size _kSize;
			double _sigmaX;
			double _sigmaY;
			int _borderType;
		};
	}
}