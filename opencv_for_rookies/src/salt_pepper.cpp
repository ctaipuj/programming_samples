#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;

void colorReduce(cv::Mat image, int div){
	int nl=image.rows;//number of lines of the matrix
	int nc=image.cols*image.channels();//total number of elements per line in the matrix
	
	for(int j=0;j<nl;j++){
	uchar* data=image.ptr<uchar>(j);//get the adress of row j
		for(int i=0;i<nc;i++){
		data[i]=data[i]/div*div+div/2; //process each pixel
		}
	}
}

void colorReduce2(cv::Mat &image, int div){//Color reduce using different way to recorer la imagen

	cv::MatIterator_<cv::Vec3b> it; //recorrer la matriz de otra forma
	it=image.begin<cv::Vec3b>();// initial position of the iterator
	
	cv::MatIterator_<cv::Vec3b> itend;
	itend=image.end<cv::Vec3b>();
	for(;it!=itend;it++){
		(*it)[0]=(*it)[0]/div*div+div/2;
		(*it)[1]=(*it)[1]/div*div+div/2;
		(*it)[2]=(*it)[2]/div*div+div/2;	
	}
}

void salt(cv::Mat image, int n){
	int i,j;
	for(int k=0;k<n;k++){
	i=rand()%image.cols;
	j=rand()%image.rows;
	
	if(image.type()==CV_8UC1){ //here we evaluate if the image is gray scale or not. # of channels
	image.at<uchar>(j,i)=255; // add white in only one channel
	} 
	else if(image.type()==CV_8UC3){
	image.at<cv::Vec3b>(j,i)[0]=255; //add "salt" in chanel 1, 2 and 3
	image.at<cv::Vec3b>(j,i)[1]=255;
	image.at<cv::Vec3b>(j,i)[2]=255;
	}
	}
}

void pepper(cv::Mat image, int n){
	int i,j;
	for(int k=0;k<n;k++){
	i=rand()%image.cols;
	j=rand()%image.rows;
	
	if(image.type()==CV_8UC1){ //here we evaluate if the image is gray scale or not. # of channels
	image.at<uchar>(j,i)=0; // add white in only one channel
	} 
	else if(image.type()==CV_8UC3){
	image.at<cv::Vec3b>(j,i)[0]=0; //add "salt" in chanel 1, 2 and 3
	image.at<cv::Vec3b>(j,i)[1]=0;
	image.at<cv::Vec3b>(j,i)[2]=0;
	}
	}
}

int main(){

	cv::Mat image=cv::imread("../B18.jpg"); //Read Image
	cv::Mat imagen=image.clone();
	cv::Mat image2=image.clone();
	salt(image,100000); //call the function that "salt" the image
	pepper(image,100000); //call the function that "pepper" the image
	
	cv::namedWindow("Image",CV_WINDOW_NORMAL);
	cv::imshow("Image",image);
	cv::imwrite("../B18_sal_y_pimienta.jpg",image); //Save the image with the modifications
	colorReduce(imagen,64);
	cv::namedWindow("Image 2",CV_WINDOW_NORMAL);
	cv::imshow("Image 2",imagen);
	
	colorReduce2(image2,64);
	cv::namedWindow("Image 3",CV_WINDOW_NORMAL);
	cv::imshow("Image 3",image2);
	
	
	cv::waitKey(0);	
}
