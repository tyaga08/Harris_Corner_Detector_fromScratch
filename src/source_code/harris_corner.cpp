#include "harris_corner.h"

HarrisCorner::HarrisCorner() {}

void HarrisCorner::find_harris_corner(cv::Mat &src_img) {
	int scale = 1, delta = 0;

	cv::GaussianBlur(src_img, smooth_img, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT);
	cv::cvtColor(smooth_img, grayscale_img, cv::COLOR_BGR2GRAY);

	cv::Sobel(grayscale_img, grad_x, CV_8U, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
	cv::Sobel(grayscale_img, grad_y, CV_8U, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);

	cv::multiply(grad_x, grad_x, Ixx);
	cv::multiply(grad_y, grad_y, Iyy);
	cv::multiply(grad_x, grad_y, Ixy);
	cv::multiply(grad_y, grad_x, Iyx);
	
	cv::Mat temp1, temp2;
	cv::multiply(Ixx, Iyy, temp1);
	cv::multiply(Ixy, Iyy, temp2);

	determinant = temp1 - temp2;
	cv::multiply(Ixx + Iyy, Ixx + Iyy, trace);
	response_matrix = determinant - alpha*trace;

	cout<<"rows "<<response_matrix.rows<<endl;
	cout<<"cols "<<response_matrix.cols<<endl;
}

