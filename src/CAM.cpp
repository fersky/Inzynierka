//============================================================================
// Name        : CAM.cpp
// Author      : Fero
// Version     : 1.1
// Copyright   : Your copyright notice
// Description : Fast, Intelligent Camera with Ethernet Interface
//============================================================================
#include "main.hpp"
#include <pthread.h>

using namespace std;
using namespace boost;
using namespace cv;
/** Function Headers */


/** Global variables */
vector<Rect> faces;



int main(){
	Controller k;
	k.modules[0]->work();
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	if(pthread_create(&tid,&attr,k.modules[2]->detector,NULL)){
std::cout<<"BLAD TWORZENIA WATKU"<<std::endl;
}
	return 0;
}



