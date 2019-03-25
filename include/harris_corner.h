#ifndef HARRIS_CORNER_H
#define HARRIS_CORNER_H

#include <iostream>
#include <cmath>
#include "opencv2/opencv.hpp"

using namespace std;

#define alpha 0.04
#define corner_threshold 180

class HarrisCorner {
public:
	HarrisCorner();

	virtual ~HarrisCorner() {}

	cv::Mat grayscale_img, smooth_img;
	cv::Mat grad_x, grad_y;
	cv::Mat response_matrix;
	cv::Mat Ixx, Iyy, Ixy, Iyx;
	cv::Mat determinant, trace;
	vector<pair<size_t, size_t> > kp_pix_index;

	void find_harris_corner(cv::Mat&);
};

#endif