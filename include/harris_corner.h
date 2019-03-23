#include <iostream>
#include <cmath>
#include "opencv2/opencv.hpp"

using namespace std;

#define alpha 0.005

class HarrisCorner {
public:
	HarrisCorner();

	virtual ~HarrisCorner() {}

	cv::Mat grayscale_img, smooth_img;
	cv::Mat grad_x, grad_y;
	cv::Mat response_matrix;
	cv::Mat Ixx, Iyy, Ixy, Iyx;
	cv::Mat determinant, trace;

	void find_harris_corner(cv::Mat&);
};

