#include "histograma.h"

using namespace std;

	histograma::histograma(){
		//constructor. Default arguments for 1D histogram
		histSize[0]=256; //256 bins
		hranges[0]=0.0; //inclusive 0
		hranges[1]=256.0; //256 exclusive
		ranges[0]=hranges;
		channels[0]=0; //channel to look
	}

	cv::Mat histograma::getHistogram(const cv::Mat &image){
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
		for (int i=0;i<256;i++){
		cout<<"Value "<<i<<" = "<<hist.at<float>(i)<<endl;
	}
			
		return hist;
	}	
	
	cv::Mat histograma::getHistogramImage(const cv::Mat &image,int x){
		cv::Mat hist=getHistogram(image); //compute histogram
		//int a=x;
		return getImageOfHistogram(hist,x);//create Image
	}

	cv::Mat histograma::getImageOfHistogram(const cv::Mat &hist,int x){ //creates de image of hist
		double maxVal=0;
		double minVal=0;
		cv::minMaxLoc(hist,&minVal,&maxVal,0,0);
		int histSize=hist.rows; //hist size
		cv::Mat histImg(histSize,histSize,CV_8U,cv::Scalar(255)); //iamge of histo

		int hpt=static_cast<int>(0.9*histSize); // "ints" the value
		for(int h=0;h<histSize;h++){ //Draw vertical line
			float binVal=hist.at<float>(h);
			if (binVal>0){
				int intensity=static_cast<int>(binVal*hpt/maxVal);
				switch (x){
				case 0:
				cv::line(histImg,cv::Point(h,histSize),cv::Point(h,(histSize-intensity)),cv::Scalar(0),1); //draw
				cv::putText(histImg,"BLUE Channel",cv::Point(80,20),CV_FONT_HERSHEY_PLAIN,1.0,cv::Scalar(0),1); // Poner texto en foto
				break;
				case 1:
				cv::line(histImg,cv::Point(h,histSize),cv::Point(h,(histSize-intensity)),cv::Scalar(0),1); //draw
				cv::putText(histImg,"GREEN Channel",cv::Point(80,20),CV_FONT_HERSHEY_PLAIN,1.0,cv::Scalar(0),1);
				break;
				case 2:
				cv::line(histImg,cv::Point(h,histSize),cv::Point(h,(histSize-intensity)),cv::Scalar(0),1); //draw
				cv::putText(histImg,"RED Channel",cv::Point(80,20),CV_FONT_HERSHEY_PLAIN,1.0,cv::Scalar(0),1);
				break;
				case -1:
				cv::line(histImg,cv::Point(h,histSize),cv::Point(h,(histSize-intensity)),cv::Scalar(0),1); //draw
				cv::putText(histImg,"Gray Scale",cv::Point(80,20),CV_FONT_HERSHEY_PLAIN,1.0,cv::Scalar(0),1);
				break;
				}	
			}		
		}
		
		return histImg;
	}
	
	void histograma::showhisto(cv::Mat histo,int x){
	cv::namedWindow("Histogram",CV_WINDOW_NORMAL);
	//int a=x;
	cv::imshow("Histogram",getHistogramImage(histo,x));
	}

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
