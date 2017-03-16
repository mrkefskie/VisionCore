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

	delete(visionCore);
}

void liveImageFeed(int ID)
{
	VisionCore::VCStruct::VideoSettings videoSettings;
	videoSettings.frame_width = 1920;
	videoSettings.frame_height = 1080;
	videoSettings.fps = 60;

	VisionCore::Core* visionCore = new VisionCore::Core(ID, videoSettings);

	visionCore->run();

	delete(visionCore);
}

int main(int argc, char** argv)
{
	//loadImageFromHarddisk("test1.jpg");

	liveImageFeed(0);




	system("pause");
	return 0;
}