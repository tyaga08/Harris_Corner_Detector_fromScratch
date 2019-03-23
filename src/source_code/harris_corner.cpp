#include "harris_corner.h"

HarrisCorner::HarrisCorner() {}

void HarrisCorner::find_harris_corner(cv::Mat &src_img) {
	int scale = 1, delta = 0;

	cv::GaussianBlur(src_img, smooth_img, cv::Size(5,5), 0, 0, cv::BORDER_DEFAULT);
	cv::cvtColor(smooth_img, grayscale_img, cv::COLOR_BGR2GRAY);

	cv::Sobel(grayscale_img, grad_x, CV_8U, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
	cv::Sobel(grayscale_img, grad_y, CV_8U, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);

	response_matrix = cv::Mat::zeros(src_img.rows, src_img.cols, CV_32F);

}