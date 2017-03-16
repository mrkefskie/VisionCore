#include <Core\Core.h>

#include <stdio.h>
#include <stdlib.h>

#include <opencv2\opencv.hpp>


void loadImageFromHarddisk(char* path)
{
	bool errorTriggered = false;

	VisionCore::Core* visionCore = new VisionCore::Core(path);

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
		printf("Something went wrong (maybe the file you specified was not found....)\n\n");
}

int main(int argc, char** argv)
{
	loadImageFromHarddisk("test1.jpg");

	system("pause");

	return 0;
}