#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;


class Histogram1D{

	private:
	
	int histSize[1]; //bins
	float hranges[2]; // range of values
	const float* ranges[1]; //pointer to the value ranges
	int channels[1]; //channel number to be examined
	
	public:
	
	Histogram1D(){
		//constructor. Default arguments for 1D histogram
		histSize[0]=256; //256 bins
		hranges[0]=0.0; //inclusive 0
		hranges[1]=256.0; //256 exclusive
		ranges[0]=hranges;
		channels[0]=0; //channel to look
	}
	//~Histogram1D(){}
	
	//compute the 1D histogram
	cv::Mat getHistogram(const cv::Mat &image){
		cv::Mat hist;
		//compute histogram
		cv::calcHist(&image,
		1, //histogram of 1 image only
		channels, //the channel used
		cv::Mat(), //no mask used
		hist, // the resulting histogram
		1, //1D histogram
		histSize, //number of bins
		ranges //pixel value range
		);
			
		return hist;
	}	
	
	cv::Mat getHistogramImage(const cv::Mat &image, int zoom=1){
		cv::Mat hist=getHistogram(image); //compute histogram
		return getImageOfHistogram(hist,zoom);//create Image
	}
	
	static cv::Mat getImageOfHistogram(const cv::Mat &hist, int zoom){ //creates de image of hist
		double maxVal=0;
		double minVal=0;
		cv::minMaxLoc(hist,&minVal,&maxVal,0,0);
		int histSize=hist.rows; //hist size
		cv::Mat histImg(histSize*zoom,histSize*zoom,CV_8U,cv::Scalar(255)); //iamge of histo
		
		int hpt=static_cast<int>(0.9*histSize); // "ints" the value
		for(int h=0;h<histSize;h++){ //Draw vertical line
			float binVal=hist.at<float>(h);
			if (binVal>0){
				int intensity=static_cast<int>(binVal*hpt/maxVal);
				cv::line(histImg,cv::Point(h*zoom,histSize*zoom),cv::Point(h*zoom,(histSize-intensity)*zoom),cv::Scalar(0),zoom); //draw
			}
		}
		return histImg;
	}
	
};

int main(){
	cv::Mat image=cv::imread("../dummy2.tif",0);//open image in B&W
	
	//create an object
	Histogram1D h;
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
}
