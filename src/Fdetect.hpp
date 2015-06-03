/*
 * Fdetect.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef FDETECT_HPP_
#define FDETECT_HPP_
#include "main.hpp"

class Fdetect : public Module {

void detectAndDisplay( cv::Mat frame );
public:

cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;
cv::String window_name;
CvCapture* capture;
cv::Mat frame;
~Fdetect();
Fdetect(Controller * k);
bool work(void*);
};


#endif /* FDETECT_HPP_ */
