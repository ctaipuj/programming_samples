#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;

int main(){
	cv::Mat image=cv::imread("../B18.jpg");
	cv::Mat logo=cv::imread("ups.png");
	cv::Mat imageROI(image,cv::Rect(image.cols-logo.cols, image.rows-logo.rows,logo.cols,logo.rows));//definir la region de interes
	logo.copyTo(imageROI);
	cv::namedWindow("Imagen",CV_WINDOW_NORMAL);
	//cv::resizeWindow("Imagen",800,600);
	cv::imshow("Imagen",image);
	cv::waitKey(0);
}
