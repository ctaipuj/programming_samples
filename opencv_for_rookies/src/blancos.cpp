#include "histograma.h"

int main(int argc,char** argv){
	
	if(argc!=2){
        cout<<"<Image_Path> not defined\n"; 
        return -1;
    }
    cv::Mat image=cv::imread(argv[1]);
    cv::imshow("RGB",image);
    cv::Mat gray;
    cv::cvtColor(image,gray,CV_BGR2GRAY);
    cv::imshow("Gray",gray);
    cv::Mat lut(1,256,CV_8U);
	for (int i=0;i<256;i++){
		lut.at<uchar>(i)=(pow(i / 255.0, 1.8) * 255.0);
	}
	cv::Mat segmented;
	cv::LUT(gray,lut,segmented);
	cv::imshow("Gamma",segmented);
    cv::Mat gray2;
    cv::Mat gray1;
    cv::GaussianBlur(gray,gray1,cv::Size(17,17),0);
    //cv::imshow("RGBlurred",gray1);
    cv::threshold(gray1,gray2,150,255,CV_THRESH_BINARY);
    //cv::imshow("Gray",gray2);
    histograma h;
    h.showhisto(gray1,-1);

	cv::waitKey(0);	
	return 0;

}
