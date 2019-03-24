#include "harris_corner.h"

HarrisCorner::HarrisCorner() {}

void HarrisCorner::find_harris_corner(cv::Mat &src_img) {
	int scale = 1, delta = 0;

	// cv::GaussianBlur(src_img, smooth_img, cv::Size(5,5), 0, 0, cv::BORDER_DEFAULT);
	cv::cvtColor(src_img, grayscale_img, cv::COLOR_BGR2GRAY);

	cv::Sobel(grayscale_img, grad_x, CV_32FC1, 1, 0, 7);//, scale, delta, cv::BORDER_DEFAULT);
	cv::Sobel(grayscale_img, grad_y, CV_32FC1, 0, 1, 7);//, scale, delta, cv::BORDER_DEFAULT);

	cv::multiply(grad_x, grad_x, Ixx);
	cv::multiply(grad_y, grad_y, Iyy);
	cv::multiply(grad_x, grad_y, Ixy);
	cv::multiply(grad_y, grad_x, Iyx);
	
	cv::GaussianBlur(Ixx, Ixx, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT);
	cv::GaussianBlur(Ixy, Ixy, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT);
	cv::GaussianBlur(Iyx, Iyx, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT);
	cv::GaussianBlur(Iyy, Iyy, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT);


	cv::Mat temp1, temp2;
	cv::multiply(Ixx, Iyy, temp1);
	cv::multiply(Ixy, Iyx, temp2);

	determinant = temp1 - temp2;
	cv::multiply(Ixx + Iyy, Ixx + Iyy, trace);
	response_matrix = determinant - alpha*trace;

	// cout<<"rows "<<response_matrix.rows<<endl;
	// cout<<"cols "<<response_matrix.cols<<endl;

	uchar count = 0;
	int corner_count = 0;

	cv::normalize(response_matrix, response_matrix, 0, 255, cv::NORM_MINMAX, CV_8U);

	for(size_t i=0; i<response_matrix.rows; i++) {
		for(size_t j=0; j<response_matrix.cols; j++) {
			count = max(count, response_matrix.at<uchar>(i,j));
			
			if(response_matrix.at<uchar>(i,j)>corner_threshold) {
				response_matrix.at<uchar>(i,j) = 255;
				corner_count++;
				cv::circle(src_img, cv::Point(j,i), 2, cv::Scalar(0,0,255), 1);
				kp_pix_index.push_back(make_pair(j,i));
			}

			else
				response_matrix.at<uchar>(i,j) = 0;
		}
	}
	// cout<<"max value = "<<(int)count<<endl;
	cout<<"Corners in this frame:  "<<corner_count<<endl;


}