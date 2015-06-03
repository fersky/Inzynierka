/*
 * Fdetect.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "Fdetect.hpp"

#include "main.hpp"
extern std::vector<cv::Rect> faces;
/** @function detectAndDisplay */
void Fdetect::detectAndDisplay( cv::Mat frame )
{

  cv::Mat frame_gray;

  cvtColor( frame, frame_gray, CV_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );

  //-- Detect faces
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30) );
/* Obrysowanie obszaru twarzy i oczu */
if(false){
  for( size_t i = 0; i < faces.size(); i++ )
  {
	  cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
	  cv::ellipse( frame, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );

	  cv::Mat faceROI = frame_gray( faces[i] );
    std::vector<cv::Rect> eyes;

    //-- In each face, detect eyes
    eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, cv::Size(30, 30) );

    for( size_t j = 0; j < eyes.size(); j++ )
     {
    	cv::Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
       int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
       cv::circle( frame, center, radius, cv::Scalar( 255, 0, 0 ), 4, 8, 0 );
     }

  }
}

  imshow( window_name, frame );
 }
bool Fdetect::work(void*){


		  if( capture )
		  {
		    while( true )
		    {
		  frame = cvQueryFrame( capture );

		  //-- 3. Apply the classifier to the frame
		      if( !frame.empty() )
		      {
		   	   sleep(1);
		   	   detectAndDisplay( frame );
		   	   //SigW(0,frame);
		   //   savelog(frame);

SigW(0,&frame);
		      }
		      else
		      { printf(" --(!) No captured frame -- Break!"); break; }

		      int c = cv::waitKey(10);
		      if( (char)c == 'c' ) { break; }
		     }
		  }
		  return 0;
}
Fdetect::~Fdetect(){}
Fdetect::Fdetect(Controller * k){
	name="Fdetect_module";

cv::String face_cascade_name = "data/haarcascade_frontalface_alt.xml";
cv::String eyes_cascade_name = "data/haarcascade_eye_tree_eyeglasses.xml";
window_name = "Capture - Face detection";
std::cout<<"FDETECT RUNNING"<<std::endl;
SigW.connect(bind(&Controller::lunit,k,_1, _2));
	//-- 1. Load the cascades
		 if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading cascade \n"); };
		 if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading cascade \n"); };

 //-- 2. Read the video stream
	  capture = cvCaptureFromCAM( -1 );}
