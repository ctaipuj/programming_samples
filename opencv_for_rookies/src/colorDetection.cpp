#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "colordetector.h"

int main()
{
	// Create image processor object
	ColorDetector cdetect;

	// Read input image
	cv::Mat image= cv::imread("../B18.jpg");
	if (!image.data)
		return 0; 

   // set input parameters
	cdetect.setTargetColor(130,190,230); // here blue sky

   // Read image, process it and display the result
	cv::namedWindow("result",CV_WINDOW_NORMAL);
	cv::imshow("result",cdetect.process(image));

	cv::waitKey();

	return 0;
}

