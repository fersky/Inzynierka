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

void * detector(void *);

int main(){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	if(pthread_create(&tid,&attr,detector,NULL)){
std::cout<<"BLAD TWORZENIA WATKU"<<std::endl;
}
	Controller k;
	k.modules[0]->work();

//	k.modules[1]



	return 0;
}

void* detector(void * param){
	std::cout<<"running detector thread"<<std::endl;
while(1){

#ifdef BRD_BUILD
	if(!digitalRead(1)) //Przyjęto LOW na pinie GPIO1 jako stan drzwi zamknięty
	SigW(2,NULL);
#endif
}
}

