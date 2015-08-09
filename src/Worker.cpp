/*
 * Worker.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"
#ifdef BRD_BUILD
#include <wiringPi.h>
#endif
bool Worker::work(void* wsk){

	std::cout<<name<<" RUNNING"<<std::endl;

	int state= *((int*)(wsk));
if(state == 1){
#ifdef BRD_BUILD
	digitalWrite(0,HIGH);
#endif
	std::cout<<"\n WORKER ustawia stan WYSOKI"<<std::endl;
	SigW(2,wsk);
}
else if (state == 2){
#ifdef BRD_BUILD
	digitalWrite(0,LOW);
#endif
	std::cout<<"\n WORKER ustawia stan NISKI"<<std::endl;
	SigW(2,wsk);
}
else
{}

	return false;
}

Worker::Worker(){

	name="WORKER";
#ifdef BRD_BUILD
	wiringPiSetup();
	pinMode (0,OUTPUT);
#endif
	/* odkomentować przy budowaniu na płytę
	system("for A in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15; do echo \"$A\" > /sys/class/gpio/export ; done ");
	system("echo out > /sys/class/gpio/gpio6_pe6/direction");
	*/
}
