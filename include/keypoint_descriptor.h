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
	// void match_corners(HarrisCorner&, cv::Mat&);
	
	// static auto desc_extr = cv::DescriptorExtractor::create("BRIEF");
	// cv::BriefDescriptorExtractor desc_extr = cv::BriefDescriptorExtractor();
	// cv::Ptr<cv::xfeatures2d::BriefDescriptorExtractor> desc_extr = cv::xfeatures2d::BriefDescriptorExtractor::create();
	cv::Ptr<cv::ORB> orb = cv::ORB::create(1000);
	// cv::Feature2D desc_extr;
	cv::Mat descriptors;
	vector<cv::KeyPoint> kp;

};

#endif