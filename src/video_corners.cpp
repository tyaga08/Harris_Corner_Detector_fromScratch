#include<iostream>
#include "harris_corner.h"

using namespace std;

int main(int argc, char** argv) {

    cv::Mat img1;
    cv::VideoCapture *vcap = new cv::VideoCapture("../images/videos/video3.mp4");

    try {
        if(!vcap->isOpened())
            throw 2;
    }

	catch(int err) {
		cerr<<"error "<<err<<": the video cannot be loaded."<<endl;
		return -1;
	}

	cv::namedWindow("video_stream_with_corners", 1);
	HarrisCorner* hc_detector = new HarrisCorner;
	cv::Mat imagetemp = cv::imread("../images/door02.jpg");
	cv::resize(imagetemp, imagetemp, cv::Size(640,480), 0, 0, cv::INTER_LANCZOS4);
	cv::VideoWriter *vwrite = new cv::VideoWriter("/home/tyagaraja/Downloads/output_video.avi", CV_FOURCC('M','J','P','G'), 10, cv::Size(640, 480));
	// vwrite->open("/home/tyagaraja/Downloads/output_video.api", CV_FOURCC('M','J','P','G'), 10, cv::Size(640, 480));

	try {
        if(!vwrite->isOpened())
            throw 3;
    }

	catch(int err) {
		cerr<<"error "<<err<<": the video cannot be written."<<endl;
		return -1;
	}

	vcap->set(cv::CAP_PROP_FPS, 10);

	while(1) {
		cv::Mat frame, img;
		*vcap >> frame;
		if(frame.empty())
			break;
		cv::resize(frame, img, cv::Size(640,480), 0, 0, cv::INTER_LANCZOS4);
		hc_detector->find_harris_corner(img);
		cv::imshow("video_stream_with_corners", img);

		vwrite->write(img);
		// if Esc key is pressed then break
		char c = (char) cv::waitKey(10);
		if(c == 27)
			break;
		// cv::waitKey(0);
	}

	vcap->release();
	vwrite->release();
	cv::destroyAllWindows();

	delete hc_detector;
	delete vcap;
	delete vwrite;

    return 0;
}