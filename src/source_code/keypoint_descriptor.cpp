#include "keypoint_descriptor.h"

KeypointDescriptor::KeypointDescriptor() {}

void KeypointDescriptor::generate_keypoints(HarrisCorner &corners, cv::Mat &img) {
    for(size_t i=0; i<corners.kp_pix_index.size(); i++) {
        size_t r = corners.kp_pix_index.at(i).second;
        size_t c = corners.kp_pix_index.at(i).first;
        float angle = atan2(corners.grad_y.at<float>(r,c),corners.grad_x.at<float>(r,c));
        int class_id = i;
        cv::Point2f pt = cv::Point2f(c,r);
        int octave = 0;
        float fsize = 2;
        kp.push_back(cv::KeyPoint(pt, fsize, angle, 0, octave, class_id));
    }
}

void KeypointDescriptor::compute_descriptor(HarrisCorner &corners, cv::Mat &img) {
    // desc_extr.detectAndCompute(img, cv::noArray(), kp, descriptors, true);
    orb->detectAndCompute(img, cv::noArray(), kp, descriptors, true);
}
