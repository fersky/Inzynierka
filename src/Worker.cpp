/*
 * Worker.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"

bool Worker::work(void* wsk){
	std::cout<<name<<" RUNNING"<<std::endl;

	int state= *((int*)(wsk));
if(state == 1){
	/* odkomentować przy budowaniu na płytę
	system("echo 1 > /sys/class/gpio/gpio6_pe6/value");
	*/
	std::cout<<"\n WORKER ustawia stan WYSOKI"<<std::endl;
}
else if (state == 0){
	/* odkomentować przy budowaniu na płytę
	system("echo 0 > /sys/class/gpio/gpio6_pe6/value");
	*/
	std::cout<<"\n WORKER ustawia stan NISKI"<<std::endl;
}

	return false;
}

Worker::Worker(){
	name="WORKER";
	/* odkomentować przy budowaniu na płytę
	system("for A in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15; do echo \"$A\" > /sys/class/gpio/export ; done ");
	system("echo out > /sys/class/gpio/gpio6_pe6/direction");
	*/
}
