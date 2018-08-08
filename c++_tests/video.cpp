#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

int main( int argc, char* argv[])
{
 cv::Mat frame;
 cv::VideoCapture cam(0);
 while (1)
 {
 	cam>>frame;
 	cv::imshow("hola",frame); 
 	cv::waitKey(20);
 }
} 
