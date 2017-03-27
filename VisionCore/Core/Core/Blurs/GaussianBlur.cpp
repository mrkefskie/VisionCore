#include "GaussianBlur.h"

VisionCore::Blurs::Gaussian::Gaussian(cv::Size kSize, double sigmaX)
{
	init(kSize, sigmaX, 0.f, cv::BorderTypes::BORDER_DEFAULT);
}

VisionCore::Blurs::Gaussian::Gaussian(cv::Size kSize, double sigmaX, double sigmaY)
{
	init(kSize, sigmaX, sigmaY, cv::BorderTypes::BORDER_DEFAULT);
}

VisionCore::Blurs::Gaussian::Gaussian(cv::Size kSize, double sigmaX, double sigmaY, int borderType)
{
	init(kSize, sigmaX, sigmaY, borderType);
}

VisionCore::Blurs::Gaussian::~Gaussian()
{
}

cv::Mat VisionCore::Blurs::Gaussian::proccessImages(cv::Mat input)
{
	cv::Mat output;

	cv::GaussianBlur(input, output, _kSize, _sigmaX, _sigmaY, _borderType);

	return output;
}

void VisionCore::Blurs::Gaussian::init(cv::Size kSize, double sigmaX, double sigmaY, int borderType)
{
	_kSize = kSize;
	_sigmaX = sigmaX;
	_sigmaY = sigmaY;
	_borderType = borderType;
}
