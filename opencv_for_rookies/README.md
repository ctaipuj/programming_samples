# OpenCV code samples (A introduction for rookies)
Here you can find some codes written in *C++* using *OpenCV*. This is a first approach for using very basic functions of *OpenCV*
## Contents:
This section has the following .cpp files and two .h files in the include directory:
### include Directory:
1. **histograma.h** Used for create an histogram
2. **colordetection.h** Used for detect colors in an image
### src Directory:
1. **7up.cpp** Detects green stuff
2. **blancos.cpp** For white stuff
3. **canny.cpp** Trying to find edges
4. **colorDetection** Detects colorful stuff
5. **colordetector** For the colordetection.h file
6. **create_image.cpp** Creates a RGB cv::Mat
7. **crop.cpp** Scales and image
8. **display_image.cpp** Shows a cv::window
9. **histo1d.cpp** Creating an histo
10. **histograma.cpp** other histo
11. **mat.cpp** How to use a cv::Mat
12. **negative.cpp** Does 255-pixel_value to an image
13. **prueba.cpp** A description for histogram class
14. **roi.cpp** Shows how to use a ROI and stick an image on other
15. **salt_pepper.cpp** black and white dots over the image
## NOTE
This two algorithms are useful when using a Kinect sensor
* **photos.cpp** Opens the kinect sensor and takes images
* **kinect.cpp** Tries to open the kinect sensor
#### When using a kinect sensor is necessary to use avin2's plugin. Find more information [here](https://github.com/avin2/SensorKinect), [here](http://blog.justsophie.com/installing-kinect-nite-drivers-on-ubuntu-14-04-and-ros-indigo/) and [here](https://docs.opencv.org/2.4/doc/user_guide/ug_kinect.html)

*Created by Nicolas May 2018*
