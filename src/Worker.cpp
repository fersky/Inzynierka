/*
 * Worker.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"

//#define BRD_BUILD
#ifdef BRD_BUILD
#include <wiringPi.h>
#endif

bool Worker::work(void* wsk){

	std::cout<<name<<" RUNNING"<<std::endl;
#ifndef TIME_TEST
int state= *(static_cast<int*>(wsk));
#else
int state = 0;
#endif
		if(state == 0){
#ifdef BRD_BUILD
	digitalWrite(0,HIGH);
#endif
	std::cout<<"WORKER sets HIGH state"<<std::endl; //otwórz drzwi
#ifndef TIME_TEST
	SigW(2,wsk);
#endif
}
else if (state == 2){
#ifdef BRD_BUILD
	digitalWrite(0,LOW);
#endif
	std::cout<<"WORKER sets LOW state"<<std::endl; //zamknij drzwi
#ifndef TIME_TEST
	SigW(2,wsk);
#endif
}
else
{}

	return false;
}

Worker::Worker(){

	name="WORKER";
#ifdef BRD_BUILD
	wiringPiSetup();
	pinMode (0,OUTPUT);	//GPIO_0 (BCM_GPIO 17) (PHYS. HEADER -> 11)
	pinMode (1,INPUT);	//GPIO_1 (BCM_GPIO 18) (PHYS. HEADER -> 12)
#endif
}


