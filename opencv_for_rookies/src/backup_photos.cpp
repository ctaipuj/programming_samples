#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>

using namespace cv;
using namespace std;

int main(){

    int check;
    stringstream dir;
    string prefix="../images/";
    time_t now=time(0);
    char* dt=ctime(&now);
    string date=dt;
    dir<<prefix<<date;
    string pwd=dir.str();
    dir.str("");
    const char* cpwd=pwd.c_str();
    
    VideoCapture kinect;
    kinect.open(CV_CAP_OPENNI);
    kinect.set( CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, CV_CAP_OPENNI_SXGA_15HZ );
    cout << "opening kinect" << endl;

    if( !kinect.isOpened() ){
        cout << "Can not open the kinect. Is it connected???" << endl;
        return -1;
    }else{
    	   check = mkdir(cpwd, 0777);
        cout << "Press s to save a snapshot"<< endl;
        cout << "Press esc to exit"<< endl;
        }
    
    if(check!=0){
    cout<<"Directory could not be created ERROR"<<endl;
    return -1;
    }else{
    cout<<"Working directory created with succes files saved to: "<< pwd<<endl;
    }
    	
    stringstream rgbfile;
    stringstream depthfile;
    stringstream cloudfile;
    stringstream disparityfile;
    stringstream disparity32file;
    stringstream maskfile;
    
    string path= "../images/";  
      
    string namergb= "/rgb_picture_";
    string namedepth="/depth_picture_";
    string namecloud="/cloud_picture_";
    string namedisparity="/disparity_picture_";
    string namedisparity32="/disparity32_picture_";
    string namemask="/mask_picture_";
    
    string type= ".tiff";
    
    char key=0;
    int i=0;
    
     if( !kinect.grab() ){
     cout << "Kinect can not grab images." << endl;
     return -1;
     }
        
    Mat color_image; //CV_8UC3
    Mat depth_image; //CV_16UC1
    Mat cloud_image; //CV_32FC3
    Mat disparity_image; //CV_8UC1
    Mat disparity_image_32; //CV_32FC1
    Mat mask_image; //CV_8UC1
    
    namedWindow("RGB image",WINDOW_NORMAL);
    //namedWindow("Depth image",WINDOW_NORMAL);
    //namedWindow("Cloud image",WINDOW_NORMAL);
    
    while (key!=27 && kinect.grab()) {
    
    kinect.retrieve(color_image, CAP_OPENNI_BGR_IMAGE);
    kinect.retrieve(depth_image, CAP_OPENNI_DEPTH_MAP);
    kinect.retrieve(cloud_image, CAP_OPENNI_POINT_CLOUD_MAP);
    kinect.retrieve(disparity_image, CAP_OPENNI_DISPARITY_MAP);
    kinect.retrieve(disparity_image_32, CAP_OPENNI_DISPARITY_MAP_32F);
    kinect.retrieve(mask_image, CAP_OPENNI_VALID_DEPTH_MASK);
    
    imshow("RGB image", color_image);
    //imshow("Depth image",depth_image);
    //imshow("Cloud image",cloud_image);
 
    if (key == 115) {
      i++;
      
      rgbfile<<pwd<<namergb<<i<<type;
      depthfile<<pwd<<namedepth<<i<<type;
      cloudfile<<pwd<<namecloud<<i<<type;
      disparityfile<<pwd<<namedisparity<<i<<type;
      disparity32file<<pwd<<namedisparity32<<i<<type;
      maskfile<<pwd<<namemask<<i<<type;
      
      string filenamergb=rgbfile.str();
      string filenamedepth=depthfile.str();
      string filenamecloud=cloudfile.str();
      string filenamedisparity=disparityfile.str();
      string filenamedisparity32=disparity32file.str();
      string filenamemask=maskfile.str();
      
      rgbfile.str("");
      depthfile.str("");
      cloudfile.str("");
      disparityfile.str("");
      disparity32file.str("");
      maskfile.str("");
      
     imwrite(filenamergb, color_image);
      imwrite(filenamedepth, depth_image);
      imwrite(filenamecloud, cloud_image);
      imwrite(filenamedisparity, disparity_image);
      imwrite(filenamedisparity32, disparity_image_32);
      imwrite(filenamemask, mask_image);
      
      cout<<i<<" picture(s) have been taken"<<endl;
      
	}
  key=waitKey(20);
  }
}
