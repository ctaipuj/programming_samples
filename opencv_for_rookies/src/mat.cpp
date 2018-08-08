#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	Mat R(620,480,CV_8UC3,Scalar(0,0,255));
	Mat B(620,480,CV_8UC3,Scalar(255,0,0));
	Mat M;
	M=0.7*R+0.3*B;//addWeighted(R,0.5,B,0.5,0.,M);//add(R,B,M);//addWeighted(R,0.5,B,0.5,0.,M);
	imshow("Matriz Roja",R);
	imshow("Matriz Azul",B);
	imshow("Matriz Morada",M);
	//cout<<"M="<< endl << M <<endl<<endl;
	Mat image=imread("../B18.jpg");
	Mat blue(image.rows,image.cols,CV_8UC3,Scalar(255,0,0));
	Mat imageblue=image*0.9+blue*0.8;
	namedWindow("Paisaje Azul",CV_WINDOW_NORMAL);
	imshow("Paisaje Azul",imageblue);
	
	vector<cv::Mat> planes;
	split(image,planes);
	namedWindow("First Channel",CV_WINDOW_NORMAL);
	imshow("First Channel",planes[0]);
	waitKey(0);
}

