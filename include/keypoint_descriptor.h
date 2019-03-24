#ifndef KEYPOINT_DESCRIPTOR_H
#define KEYPOINT_DESCRIPTOR_H

#include <iostream>
#include <cmath>
#include "opencv2/opencv.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "harris_corner.h"

using namespace std;

class KeypointDescriptor {

public:

	KeypointDescriptor();
 
	virtual ~KeypointDescriptor() {}

	void generate_keypoints(HarrisCorner&, cv::Mat&);
	void compute_descriptor(HarrisCorner&, cv::Mat&);
	
	cv::Feature2D desc_extr;
	cv::Mat descriptors;
	vector<cv::KeyPoint> kp;
	
};

#endif