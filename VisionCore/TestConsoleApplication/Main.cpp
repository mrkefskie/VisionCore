#include <Core\Core.h>

#include <stdio.h>
#include <stdlib.h>

#include <opencv2\opencv.hpp>

bool errorTriggered;

int main(int argc, char** argv)
{
	errorTriggered = false;

	Core::Core* visionCore = new Core::Core("0.bmp");

	if (visionCore->load())
	{
		cv::Mat image = visionCore->getInput();

		if (image.rows > 1 && image.cols > 1)
		{
			cv::imshow("testImage", image);

			cv::waitKey(0);
		}
		else
			errorTriggered = true;
	}
	else
		errorTriggered = true;

	if (errorTriggered == true)
	{
		printf("Something went wrong (maybe the file you specified was not found....)\n\n");
		system("pause");
	}

	return 0;
}