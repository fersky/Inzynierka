/*
 * Worker.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"
#define BRD_BUILD 
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
	std::cout<<"\n WORKER ustawia stan WYSOKI"<<std::endl; //otwórz drzwi
	SigW(2,wsk);
}
else if (state == 2){
#ifdef BRD_BUILD
	digitalWrite(0,LOW);
#endif
	std::cout<<"\n WORKER ustawia stan NISKI"<<std::endl; //zamknij drzwi
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
	pinMode (0,OUTPUT);	//GPIO_0 (BCM_GPIO 17) (PHYS. HEADER -> 11)
	pinMode (1,INPUT);	//GPIO_1 (BCM_GPIO 18) (PHYS. HEADER -> 12)
#endif
}

void * Worker::detector(void * param){

while(1){
#ifdef BRD_BUILD
	if(!digitalRead(1)) //Przyjęto LOW na pinie GPIO1 jako stan drzwi zamknięty
	SigW(2,NULL);
#endif
}
}
