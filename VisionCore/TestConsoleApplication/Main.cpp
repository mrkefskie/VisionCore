#include <Core.h>

#include <stdio.h>
#include <stdlib.h>

#include <opencv2\opencv.hpp>

int main(int argc, char** argv)
{
	double a = 7.4;
	int b = 99;

	printf("a + b = %f\n", Core::MathTest::Add(a, b));
	printf("a - b = %f\n", Core::MathTest::Subtract(a, b));
	printf("a * b = %f\n", Core::MathTest::Multiply(a, b));
	printf("a / b = %f\n", Core::MathTest::Divide(a, b));


	cv::Mat image = Core::MathTest::getImage("0.bmp");
	cv::imshow("TestImage", image);

	cv::waitKey(0);

	//system("pause");

	return 0;
}