/*
 * Object_Detection.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef Object_Detection_HPP_
#define Object_Detection_HPP_
#include "main.hpp"

class Object_Detection : public Module {

bool detectAndDisplay( cv::Mat frame );
public:

cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;
cv::String window_name;
cv::VideoCapture capture;
cv::Mat frame;
~Object_Detection();
Object_Detection(Controller * k);
bool work(void*);
};


#endif /* Object_Detection_HPP_ */
