#ifndef HISTOGRAMA
#define HISTOGRAMA

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;


class histograma{

	private:
	
	int histSize[1]; //bins
	float hranges[2]; // range of values
	const float* ranges[1]; //pointer to the value ranges
	int channels[1]; //channel number to be examined
	int x;
	
	public:
	
	histograma();
	//~Histogram1D(){}
	
	//compute the 1D histogram
	cv::Mat getHistogram(const cv::Mat &image);
	
	cv::Mat getHistogramImage(const cv::Mat &image,int x);

	cv::Mat getImageOfHistogram(const cv::Mat &hist, int x);
	
	void showhisto(cv::Mat histo, int x);
};
#endif

/*int main(){
	cv::Mat image=cv::imread("../rgb_picture_84.tiff");//open image in B&W
	
	//create an object
	histograma h;
	//h.setchannel(1);
	cv::Mat histo=h.getHistogram(image);
	
	//loop to see data in screen
	for (int i=0;i<256;i++){
		cout<<"Value "<<i<<" = "<<histo.at<float>(i)<<endl;
	}
	cv::namedWindow("Histogram");
	cv::imshow("Histogram",h.getHistogramImage(image));
	cv::Mat thresholded;
	cv::threshold(image,//image
	thresholded,//(converted
	50,//threshold
	255,//value assigned to pixel
	cv::THRESH_BINARY);//type of exit
	cv::namedWindow("Binary",CV_WINDOW_NORMAL);
	cv::imshow("Binary",thresholded);
	cv::waitKey(0);
	return 0;
}*/
