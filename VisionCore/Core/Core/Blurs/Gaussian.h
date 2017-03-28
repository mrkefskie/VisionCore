#pragma once

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	namespace Blurs
	{
		class Gaussian
		{
		public:
			Gaussian(cv::Size kSize, double sigmaX) { init(kSize, sigmaX, 0.f, cv::BorderTypes::BORDER_DEFAULT); }
			Gaussian(cv::Size kSize, double sigmaX, double sigmaY) { init(kSize, sigmaX, sigmaY, cv::BorderTypes::BORDER_DEFAULT); }
			Gaussian(cv::Size kSize, double sigmaX, double sigmaY, int borderType) { init(kSize, sigmaX, sigmaY, borderType); }

			cv::Mat proccessImage(cv::Mat input)
			{
				cv::Mat output;
				cv::GaussianBlur(input, output, _kSize, _sigmaX, _sigmaY, _borderType);
				return output;
			}
			
			cv::Size getKSize() { return _kSize; }
			double getSigmaX() { return _sigmaX; }
			double getSigmaY() { return _sigmaY; }
			int getBorderType() { return _borderType; }

			void setKSize(cv::Size kSize) { _kSize = kSize; }
			void setSigmaX(double sigmaX) { _sigmaX = sigmaX; }
			void setSigmaY(double sigmaY) { _sigmaY = sigmaY; }
			void setBorderType(int borderType) { _borderType = borderType; }

		private:
			void init(cv::Size kSize, double sigmaX, double sigmaY, int borderType) { _kSize = kSize; _sigmaX = sigmaX; _sigmaY = sigmaY; _borderType = borderType; }

			cv::Size _kSize;
			double _sigmaX;
			double _sigmaY;
			int _borderType;
		};
	}
}