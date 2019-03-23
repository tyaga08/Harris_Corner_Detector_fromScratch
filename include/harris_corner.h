#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;

class HarrisCorner {
public:
	HarrisCorner();

	virtual ~HarrisCorner() {}

	cv::Mat grayscale_img, smooth_img;
	cv::Mat grad_x, grad_y;
	cv::Mat response_matrix;

	void find_harris_corner(cv::Mat &src_img);
};

