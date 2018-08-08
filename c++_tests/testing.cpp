#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main( int argc, char* argv[])
{
 Mat frame;
 VideoCapture cam(0);
 while (1)
 {
 	cam>>frame;
 	imshow("hola",frame); 
 	waitKey(20);
 }
} 
