#include "colordetector.h"
	
cv::Mat ColorDetector::process(const cv::Mat &image) {
	
	  // re-allocate binary map if necessary
	  // same size as input image, but 1-channel
	  result.create(image.rows,image.cols,CV_8U);

	  // get the iterators
	  cv::Mat_<cv::Vec3b>::const_iterator it= image.begin<cv::Vec3b>();
	  cv::Mat_<cv::Vec3b>::const_iterator itend= image.end<cv::Vec3b>();
	  cv::Mat_<uchar>::iterator itout= result.begin<uchar>();

	  // for each pixel
	  for ( ; it!= itend; ++it, ++itout) {
        
		// process each pixel ---------------------

		  // compute distance from target color
		  if (getDistance(*it)<minDist) {

			  *itout= 255;

		  } else {

			  *itout= 0;
		  }

        // end of pixel processing ----------------
	  }

	  return result;
}

