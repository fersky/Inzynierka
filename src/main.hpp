/*
 * main.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef MAIN_HPP_
#define MAIN_HPP_
<<<<<<< HEAD

//#define TIME_TEST
//#define BRD_BUILD

=======
<<<<<<< HEAD
#define TIME_TEST
//#define BRD_BUILD
#define TIME_TEST
=======
//#define BRD_BUILD
#define TIME_TEST
>>>>>>> 60c89a96216ab0c2086ea40dd6ee8575ecb81f68
>>>>>>> b3ac8e18fd3c3b76500d55126d8894b7f3152b4f

#define FD 0
#define WR 2
#define LG 1

#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <cstddef>

#include "Module.hpp"
#include "Controller.hpp"
#include "Object_Detection.hpp"
#include "Logger.hpp"
#include "Worker.hpp"
#include "Time_Test.hpp"

#include <pthread.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <string.h>
#include <assert.h>
#ifdef BRD_BUILD
#include <wiringPi.h>
#endif
#endif /* MAIN_HPP_ */
