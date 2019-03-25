#ifndef MATCHER_HOMOGRAPHY_WARPING_H
#define MATCHER_HOMOGRAPHY_WARPING_H

#include <iostream>
#include "keypoint_descriptor.h"

using namespace std;

class MatcherHomographyWarping {

public:
    MatcherHomographyWarping();
    virtual ~MatcherHomographyWarping() {}

    cv::BFMatcher matcher;
    


};

#endif