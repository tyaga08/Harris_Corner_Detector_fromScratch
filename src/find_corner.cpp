#include <iostream>
#include "harris_corner.h"

using namespace std;

int main(int argc, char** argv) {
    cv::Mat img, img1;
    try {
        img1 = cv::imread("../images/camera_images/img4.jpg");
        if(!img1.data)
            throw 1;
    }
    
    catch(int err) {
        cerr<<"error "<<err<<": cannot read the image"<<endl;
        return -1;
    }

	cv::resize(img1, img, cv::Size(640,480), 0, 0, cv::INTER_LANCZOS4);

	HarrisCorner *hc_detector = new HarrisCorner;
	hc_detector->find_harris_corner(img);

    cv::imshow("actual img", img);
	// cv::imshow("grad_x", hc_detector->grad_x);
	// cv::imshow("grad_y", hc_detector->grad_y);
	cv::imshow("response matrix", hc_detector->response_matrix);
    cv::waitKey();
	delete hc_detector;
    return 0;
}