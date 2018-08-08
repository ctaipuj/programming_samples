#include "histograma.h"

int main(int argc,char** argv){
	
	if(argc!=2){
	cout<<"<Image_Path> not defined\n";
	return -1;
	}
	
	histograma h;
	
	cv::Mat image=cv::imread(argv[1]);
	cv::Mat gray;
	cv::cvtColor(image,gray,CV_BGR2GRAY);
	cv::imshow("Gray",gray);
	vector<cv::Mat> canales;
	cv::split(image,canales);
	cv::imshow("G",canales[1]);
	h.showhisto(canales[1],1);
	
	cv::Mat blurred;
	cv::GaussianBlur(canales[1],blurred,cv::Size(7,7),0);
	cv::Mat seg;
	cv::threshold(blurred,seg,95,255,CV_THRESH_BINARY);
	cv::imshow("Seg",seg);
	
	cv::Mat dilate;
	cv::Mat kernel=cv::Mat::ones(3,3,CV_8U);
	cv::dilate(seg,dilate,kernel,cv::Point(-1,-1),13);
	cv::imshow("dilate",dilate);
	
	/*cv::Mat closing;
	cv::Mat kernel=cv::Mat::ones(21,21,CV_8U);
	cv::Mat kernel2=cv::Mat::ones(7,7,CV_8U);
	cv::morphologyEx(seg,closing,1,kernel);
	cv::Mat finish;
	cv::morphologyEx(closing,finish,0,kernel2);
	cv::imshow("Close",finish);
	*/
	cv::waitKey(0);
	return 0;
}
