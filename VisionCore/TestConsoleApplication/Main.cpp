#include <Core\Core.h>

#include <stdio.h>
#include <stdlib.h>

#include <opencv2\opencv.hpp>

int main(int argc, char** argv)
{
	Core::Core* visionCore = new Core::Core("0.bmp");

	if (visionCore->load())
	{
		cv::Mat image = visionCore->getImage();

		cv::imshow("testImage", image);

		cv::waitKey(0);
	}
	else
	{
		printf("Something went wrong (maybe the file you specified was not found....)\n\n");
		system("pause");
	}

	return 0;
}