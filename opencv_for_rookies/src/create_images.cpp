#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;

cv::Mat function(){
//Create an image
cv::Mat ima(240,320,CV_8U,cv::Scalar(100)); //Image in grayscale
//Return It
return ima;
}

int main(){

	//Getting a gray level image from the function
	cv::Mat gray=function();
	
	//create an image 240 rows 320 columns
	cv::Mat image1(240,320,CV_8U,100);
	
	//create a red color image
	//channel order is BGR
	cv::Mat image2(240,320,CV_8UC3,cv::Scalar(0,0,255));
	
	//gray level image
	cv::Mat image2_1(500,500,CV8UC3,cv::Scalar(100));
	
	//Not initialized color image
	cv::Mat image2_2(320,240,CV_8UC3);
	
	//to point to the same data block
	
	cv::Mat image4(image3);
	image1=image3;
	
	//New copies of the source images
	cv::image3.copyTo(image2);
	cv::Mat image5=image3.clone();
	
	//Convert the image into a floating point image [0,1] Las imagenes deben tener el mismo numero de canales
	image1.convertTo(image2,CV32F,1/255.0,0.0);	
}
