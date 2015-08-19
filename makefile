#!/bin/sh
g++ src/Time_Test.cpp src/Object_Detection.cpp src/Worker.cpp src/CAM.cpp src/Controller.cpp src/Logger.cpp -o cam -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_objdetect -lboost_signals  -L/usr/lib/uv4l/uv4lext/armv6l -luv4lext -Wl,-rpath,/usr/lib/uv4l/uv4lext/armv6l -lwiringPi -lpthread -std=c++0x
