#pragma once

#include <opencv2\opencv.hpp>

namespace VisionCore
{
	namespace Blurs
	{
		class Average
		{
		public:
			Average(cv::Size kSize) { init(kSize, cv::Point(-1, -1), cv::BorderTypes::BORDER_DEFAULT); }
			Average(cv::Size kSize, cv::Point anchor) { init(kSize, anchor, cv::BorderTypes::BORDER_DEFAULT); }
			Average(cv::Size kSize, cv::Point anchor, int borderType) { init(kSize, anchor, borderType); }
			
			cv::Mat processImage(cv::Mat input)
			{
				cv::Mat output;
				cv::blur(input, output, _kSize, _anchor, _borderType);
				return output;
			}

			cv::Size getKSize() { return _kSize; }
			cv::Point getAnchor() { return _anchor; }
			int getBorderType() { return _borderType; }

			void setKSize(cv::Size kSize) { _kSize = kSize; }
			void setAnchor(cv::Point anchor) { _anchor = anchor; }
			void setBorderType(int borderType) { _borderType = borderType; }

		private:
			void init(cv::Size kSize, cv::Point anchor, int borderType) { _kSize = kSize; _anchor = anchor; _borderType = borderType; }

			cv::Size _kSize;
			cv::Point _anchor;
			int _borderType;
		};
	}
}
