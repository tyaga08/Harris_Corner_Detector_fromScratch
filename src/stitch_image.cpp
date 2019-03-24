#include <iostream>
#include <vector>
#include "harris_corner.h"
#include "keypoint_descriptor.h"

using namespace std;

int main(int argc, char** argv) {

    vector<cv::Mat*> img_stream;
    
    for(int i=1; i<=4; i++) {
        try {
            string filename = "../images/camera_images/img" + to_string(i)+".jpg";
			cv::Mat *img = new cv::Mat;
			*img = cv::imread(filename);
			if(!img->data)
				throw 1;
			else {
				cv::resize(*img, *img, cv::Size(640,480), 0, 0, cv::INTER_LANCZOS4);
				img_stream.push_back(img);
			}
		}
		
		catch(int err) {
			cerr<<"error "<<err<<": cannot read the image"<<endl;
        	return -1;
		}
    }

	vector<HarrisCorner*> hc_detector;
	for(int i=0; i<img_stream.size(); i++) {
		HarrisCorner *temp = new HarrisCorner;
		hc_detector.push_back(temp);
	}

	for(int i=0; i<img_stream.size(); i++) {
		hc_detector.at(i)->find_harris_corner(*img_stream.at(i));
	}

	vector<KeypointDescriptor*> kp_des;
	for(int i=0; i<img_stream.size(); i++) {
		KeypointDescriptor* temp = new KeypointDescriptor;
		kp_des.push_back(temp);
	}

	for(int i=0; i<img_stream.size(); i++) {
		kp_des.at(i)->generate_keypoints(*hc_detector.at(i), *img_stream.at(i));
		kp_des.at(i)->compute_descriptor(*hc_detector.at(i), *img_stream.at(i));
	}


	for(int i=img_stream.size()-1; i>=0; i--) {
		delete img_stream.at(i);
		delete hc_detector.at(i);
		delete kp_des.at(i);
	}

    return 0;
}