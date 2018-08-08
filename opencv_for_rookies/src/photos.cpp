#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/videoio/videoio.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>


using namespace std;
using namespace cv;

void properties();

static void usage(){
    std::cerr << "Usage of kinect photoshoot studio. " //<< argv[0] << " <option(s)> SOURCES"
              << "Options:\n\n"
              << "\t1. Argument: Save mode allows users to save images -s for saving -n otherwise\n\n"
              << "\t2. Argument: Specify the viewing mode -m for mask depth mask viewing, -g for rgb and -b for both\n\n"
              << "\t3. Argument: Allows saving depth cloud data -c to allow the mode -n otherwise\n\n"
              << "\t4. Argument: Allows saving disparity data -d to allow the mode -n otherwise\n\n"
              << "\t5. Argument: Optional set the number of the first image\n\n"
              << "\t6. Argument: To show kinect properties: -p.\n\n"
              << "\t7. Argument: -vga for VGA. SXGA default\n\n\n"
              << "Press ESC to exit\n"
              << "The images are saved in the images folder that MUST be in the parent folder\n\n\n\n"
              << "\t\t\t\tCTAI-PUJ 2017 NICO\n"
              << std::endl;
}

int main(int argc, char*argv[]){

	if (argc<3 || argc>8){
		usage();
		return 0;
	}

	string param1=argv[1];
	string param2=argv[2];
	string param3;
	string param4;
	string param5;
	string param6;
	string param7;
	
	if(argc==4)
	param3=argv[3];
	if(argc==5)
	param4=argv[4];
	if(argc==6)
	param5=argv[5];
	stringstream index(param5);
	if(argc==7)
	param6=argv[6];
	if(argc==8)
	param7=argv[7];
	
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
    if(param7=="-vga"||param7=="-VGA")
    kinect.set( CV_CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, CV_CAP_OPENNI_VGA_30HZ );
    else
    kinect.set( CV_CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, CV_CAP_OPENNI_SXGA_15HZ );
    cout << "opening kinect" << endl;

    if( !kinect.isOpened() ){
        cout << "Can not open the kinect. Is it connected???" << endl;
        return -1;
    }else if(param1=="-s"||param1=="-S"){
    	   check = mkdir(cpwd, 0777);
        cout << "Press s to save a snapshot"<< endl;
        cout << "Press esc to exit"<< endl;
    		if(check!=0){
    		cout<<"Directory could not be created ERROR verify there is a images directory in the parent directory"<<endl;
    		return -1;
    		}else{
    		cout<<"Working directory created with succes files saved to: "<< pwd<<endl;
    		}
    	}
    //if(argv[1]=="s"||argv[1]=="S"){	
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
    //}
    
    char key=0;
    int i;
    
    if(argc>5){
    	index>>i;
    	i-1;
    }else{
    	i=0;
    }
    
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
    
    cv::Mat color_image_test;
    
    if(param6=="-p"||param6=="-P")
		//properties();
    	cout<<"\tKinect properties:\n\n"
		<<"\t\tMaximun supported depth in mm: "<<kinect.get(CV_CAP_PROP_OPENNI_FRAME_MAX_DEPTH)<<"\n"
		<<"\t\tCamera baseline in mm: "<<kinect.get(CV_CAP_PROP_OPENNI_BASELINE)<<"\n"
		<<"\t\tKinect Focal Length in pixels: "<<kinect.get(CV_CAP_PROP_OPENNI_FOCAL_LENGTH)<<"\n"
		<<"\t\tFrame width in pixels: "<<kinect.get(CV_CAP_PROP_FRAME_WIDTH)<<"\n"
		<<"\t\tFrame Height in pixels: "<<kinect.get(CV_CAP_PROP_FRAME_HEIGHT)<<"\n"
		<<"\t\tFrame rate in FPS: "<<kinect.get(CV_CAP_PROP_FPS)<<"\n"
		<<endl;
    //namedWindow("Depth image",WINDOW_NORMAL);
    //namedWindow("Cloud image",WINDOW_NORMAL);
    
    while (key!=27 && kinect.grab()) {
    
    kinect.retrieve(color_image, CV_CAP_OPENNI_BGR_IMAGE);
    kinect.retrieve(depth_image, CV_CAP_OPENNI_DEPTH_MAP);
    kinect.retrieve(cloud_image, CV_CAP_OPENNI_POINT_CLOUD_MAP);
    kinect.retrieve(disparity_image, CV_CAP_OPENNI_DISPARITY_MAP);
    kinect.retrieve(disparity_image_32, CV_CAP_OPENNI_DISPARITY_MAP_32F);
    kinect.retrieve(mask_image, CV_CAP_OPENNI_VALID_DEPTH_MASK);
    
    if(param2=="-m"||param2=="-M"||param2=="-b"||param2=="-B"){
    
    //descomentar si se quiere usar una mascara 
    //cv::Mat depth_real;
    //depth_real=cv::imread("../mask_picture_84.tiff",CV_8UC1);

    cv::Mat no_depth_data(color_image.size(),CV_8UC3,Scalar(0,0,255));
    cv::Mat restricted_area_color_image;
    cv::Mat mask_image_big;
   //depth_real instead of mask_image
    cv::resize(mask_image,mask_image_big,color_image.size(),INTER_NEAREST);
    cv::bitwise_not(mask_image_big,mask_image_big);
    
	for(int k=0;k<color_image.cols;k++){
   		for(int j=0;j<color_image.rows;j++){  
    			if(mask_image_big.at<uchar>(cv::Point(k,j))!=255)
				no_depth_data.at<cv::Vec3b>(j,k)[2]=0;
		}
	}
	
	cv::addWeighted(no_depth_data,0.5,color_image,0.9,0,restricted_area_color_image);
    	cv::circle(restricted_area_color_image,cv::Point(1280/2,1024/2),5,cv::Scalar(0,252,124),-1);
	namedWindow("Worktable area with data (Red means no depth data)",WINDOW_NORMAL);
	cv::imshow("Worktable area with data (Red means no depth data)",restricted_area_color_image);
	}
    //imshow("Depth image",depth_image);
    //imshow("Cloud image",cloud_image);
    //////////////////////////////////////////////// CODIGO AGREGADO X MI
    color_image_test=color_image.clone();
    cv::line(color_image_test,cv::Point(0,color_image.rows/2),cv::Point(color_image.cols,color_image.rows/2),cv::Scalar(0,252,124),2);
    cv::line(color_image_test,cv::Point(color_image.cols/2,0),cv::Point(color_image.cols/2,color_image.rows),cv::Scalar(0,252,124),2);
    
    //FOUR FAKE LINES TO TEST THE WORKTABLE Describing my ROI...
    cv::line(color_image_test,cv::Point(color_image.cols/32,color_image.rows/8),cv::Point(color_image.cols*7/8,color_image.rows/8),cv::Scalar(0,0,255),2);
    cv::line(color_image_test,cv::Point(color_image.cols*7/8,color_image.rows/8),cv::Point(color_image.cols*7/8,color_image.rows*22/32),cv::Scalar(0,0,255),2);
    cv::line(color_image_test,cv::Point(color_image.cols/32,color_image.rows*22/32),cv::Point(color_image.cols*7/8,color_image.rows*22/32),cv::Scalar(0,0,255),2);
    cv::line(color_image_test,cv::Point(color_image.cols/32,color_image.rows/8),cv::Point(color_image.cols/32,color_image.rows*22/32),cv::Scalar(0,0,255),2);
    cv::putText(color_image_test,"ROI 1.0",cv::Point(color_image.cols/32,-5+color_image.rows/8),CV_FONT_HERSHEY_SIMPLEX,0.8,cv::Scalar(0,0,255),3);
    
    
    cv::line(color_image_test,cv::Point(color_image.cols/4,0),cv::Point(color_image.cols/4,color_image.rows),cv::Scalar(0,255,255),2);
    cv::line(color_image_test,cv::Point(color_image.cols*3/4,0),cv::Point(color_image.cols*3/4,color_image.rows),cv::Scalar(0,255,255),2);
    cv::line(color_image_test,cv::Point(0,color_image.rows/4),cv::Point(color_image.cols,color_image.rows/4),cv::Scalar(0,255,255),2);
    cv::line(color_image_test,cv::Point(0,color_image.rows*3/4),cv::Point(color_image.cols,color_image.rows*3/4),cv::Scalar(0,255,255),2);
    
    
    cv::putText(color_image_test,"1",cv::Point(0,24),CV_FONT_HERSHEY_SIMPLEX,0.8,cv::Scalar(50,205,50),2);
    cv::putText(color_image_test,"2",cv::Point(color_image.cols/2,24),CV_FONT_HERSHEY_SIMPLEX,0.8,cv::Scalar(50,205,50),2);
    cv::putText(color_image_test,"3",cv::Point(0,color_image.rows/2+24),CV_FONT_HERSHEY_SIMPLEX,0.8,cv::Scalar(50,205,50),2);
    cv::putText(color_image_test,"4",cv::Point(color_image.cols/2,color_image.rows/2+24),CV_FONT_HERSHEY_SIMPLEX,0.8,cv::Scalar(50,205,50),2);
    
    if(param2=="-g"||param2=="-G"||param2=="-b"||param2=="-B"){
    	namedWindow("Ground Truth",WINDOW_NORMAL);
    	cv::imshow("Ground Truth",color_image_test);
    }
    ///////////////////////////////////////////////
 
    if (key == 115 && (param1=="-s"||param1=="-S")){
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
      
      /////////////////////// CODIGO AGREGADO X MI 
      rgbfile.str("");
      rgbfile<<pwd<<"/ground_truth_rgb_picture_"<<i<<type;
      string filenamergb2=rgbfile.str();
      cv::imwrite(filenamergb2,color_image_test);
      //////////////////////      
      
      rgbfile.str("");
      depthfile.str("");
      cloudfile.str("");
      disparityfile.str("");
      disparity32file.str("");
      maskfile.str("");
      
	 imwrite(filenamergb, color_image);
      imwrite(filenamedepth, depth_image);
      if(param3=="-c"||param3=="-C")
      	imwrite(filenamecloud, cloud_image);
      if(param4=="-d"||param4=="-D"){
      	imwrite(filenamedisparity, disparity_image);
      	imwrite(filenamedisparity32, disparity_image_32);
      }
      imwrite(filenamemask, mask_image);
      
      //ARREGALAR
      cout<<i<<" picture(s) have been taken"<<endl;
      
	}
  key=waitKey(20);
  }
}

/*void properties(){
	cout<<"\tKinect properties:\n\n"
		<<"\t\tMaximun supported depth in mm: "<<kinect.get(CV_CAP_PROP_OPENNI_FRAME_MAX_DEPTH)<<"\n"
		<<"\t\tCamera baseline in mm: "<<kinect.get(CV_CAP_PROP_OPENNI_BASELINE)<<"\n"
		<<"\t\tKinect Focal Length in pixels: "<<kinect.get(CV_CAP_PROP_OPENNI_FOCAL_LENGTH)<<"\n"
		<<"\t\tFrame width in pixels: "<<kinect.get(CV_CAP_PROP_FRAME_WIDTH)<<"\n"
		<<"\t\tFrame Height in pixels: "<<kinect.get(CV_CAP_PROP_FRAME_HEIGHT)<<"\n"
		<<"\t\tFrame rate in FPS: "<<kinect.get(CV_CAP_PROP_FPS)<<"\n"
		<<endl;
}*/
