//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

#include "histograma.h"

using namespace std;


int main(int argc, char** argv){

	if ( argc != 2 )
    {
        cout<<"<Image_Path> not defined\n"; //Incluir los argumentos al momento de abrir la pagina
        return -1;
    }
    	cv::namedWindow("RGB",CV_WINDOW_NORMAL);
	cv::namedWindow("Gray",CV_WINDOW_NORMAL);
	cv::namedWindow("Blurred",CV_WINDOW_NORMAL);
	cv::namedWindow("Edges",CV_WINDOW_NORMAL);
	cv::namedWindow("Contours",CV_WINDOW_NORMAL);
	cv::namedWindow("Contornos",CV_WINDOW_NORMAL);
    	cv::namedWindow("Segmented",CV_WINDOW_NORMAL);
    	cv::namedWindow("opening",CV_WINDOW_NORMAL);
    	
	cv::Mat image=cv::imread(argv[1]);
	cv::imshow("RGB",image);
	//r.showhisto(image);
	cv::Mat gray;
	cvtColor(image,gray,CV_BGR2GRAY);
	cv::imshow("Gray",gray);
	//cv::Mat result;
	//cv::equalizeHist(gray,result);
	//cv::imshow("Equalized",result);
	cv::Mat blurred;
	cv::GaussianBlur(gray,blurred,cv::Size(11,11),0);
	cv::imshow("Blurred",blurred);
	cv::Mat edges;
	cv::Canny(blurred,edges,120,250);
	cv::imshow("Edges",edges);
	cv::Mat contours=edges.clone();
	vector<cv::Mat> contornos;//vector<vector<cv::Point> > contornos;
	cv::findContours(contours,contornos,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
	cv::imshow("Contours",contours);
	cv::drawContours(image,contornos,-1,cv::Scalar(255,255,255),CV_FILLED,8);
	for(int i=0;i<contornos.size();i++){
	double area=cv::contourArea(contornos[i]);
	cout<<"Area del contorno "<<i+1<<" "<<area<<endl;
	}	
	imshow("Contornos",image);
	cv::drawContours(gray,contornos,-1,cv::Scalar(255,255,255),CV_FILLED,8);
	int dim(256);
	cv::Mat lut(1,&dim,CV_8U);
	for (int i=0;i<256;i++){
		if(i<95){
		lut.at<uchar>(i)=0;
	}else{
		lut.at<uchar>(i)=255;
	}
	}
	cv::Mat segmented;
	cv::LUT(gray,lut,segmented);
	cv::imshow("Segmented",segmented);
	
	cv::Mat kernel=cv::Mat::ones(11,11,CV_8U);
	cv::Mat kernel2=cv::Mat::ones(5,5,CV_8U);
	cv::Mat opening;
	cv::Mat opening1;	
	cv::Mat opening2;	
	cv::Mat opening3;	
	cv::Mat opening4;
	cv::Mat opening5;			
	cv::morphologyEx(segmented,opening,1,kernel);
	cv::morphologyEx(opening,opening1,0,kernel2);
	
	cv::imshow("opening",opening);
	/*cv::imwrite("/home/ctai/algorithm/document/opening.png",opening);
	cv::imwrite("/home/ctai/algorithm/document/segmentation.png",segmented);
	cv::imwrite("/home/ctai/algorithm/document/edges.png",edges);*/
	
	cv::waitKey(0);
	return 0;
}
	//(sizeof(contornos)/1
