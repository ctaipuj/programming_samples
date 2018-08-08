#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
 
int main(){

	cv::Mat rgb=cv::imread("../rgb_picture_4.tiff");
	cv::Mat mask=cv::imread("../mask_picture_4.tiff");
	
	cv::Mat rgb_resized;
	cv::resize(mask,rgb_resized,rgb.size());
	
	cv::Mat sum;
	
	cv::addWeighted(rgb,0.9,rgb_resized,0.7,0.0,sum);//cv::addWeighted(rgb_resized,0.9,mask,0.7,0.0,sum);
	cv::imshow("Sum",sum);
	cv::imshow("rgb",rgb_resized);
	cv::imshow("Mask",mask);
	
	vector<cv::Mat> channels;
	
	cv::split(rgb_resized,channels);
	
	/*cv::imshow("1",channels[0]);
	cv::imshow("2",channels[1]);
	cv::imshow("3",channels[2]);
	cout<<channels[1];*/
	cv::imwrite("../depth_mask.tiff",channels[0]);
	cv::waitKey(0);	
}
