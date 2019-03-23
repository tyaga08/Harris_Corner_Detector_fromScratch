#include <iostream>
#include "harris_corner.h"

using namespace std;

int main(int argc, char** argv) {
    cv::Mat img1;
    try {
        img1 = cv::imread("../images/door02.jpg");
        if(!img1.data)
            throw 1;
    }
    
    catch(int err) {
        cerr<<"error "<<err<<": cannot read the image"<<endl;
        return 1;
    }

	HarrisCorner *hc_detector = new HarrisCorner;
	hc_detector->find_harris_corner(img1);

    cv::imshow("actual img", img1);
	cv::imshow("grad_x", hc_detector->grad_x);
	cv::imshow("grad_y", hc_detector->grad_y);
	cv::imshow("response matrix", hc_detector->response_matrix);
    cv::waitKey();
	delete hc_detector;
    return 0;
}