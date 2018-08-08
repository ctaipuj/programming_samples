#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

cv::Mat applyLookUp(const cv::Mat& image,const cv::Mat& lookup);

int main(){
	cv::Mat image=cv::imread("../rgb_picture_7.tiff");
	int dim(256);//definir tabla, para realizar la inversion.
	cv::Mat lut(1,&dim,CV_8U);// 1 dimension, 256 entradas, uchar
	for (int i=0;i<256;i++){
		lut.at<uchar>(i)=255-i;
	}
	cv::Mat negative=applyLookUp(image,lut);
	cv::namedWindow("Negative",CV_WINDOW_NORMAL);
	cv::imshow("Negative",negative);
	cv::waitKey(0);		
}

cv::Mat applyLookUp(const cv::Mat& image,const cv::Mat& lookup){
	cv::Mat result;
	cv::LUT(image,lookup,result);//apply the look table
	return result;
}
