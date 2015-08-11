/*
 * Controller.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"
#define FD 0
#define WR 2
#define LG 1
bool Controller::lunit(int nr,void* wsk){
	int state= -1;

	std::cout<<"CONTROLLER "<<"RECEIVED SIGNAL : " << nr<<std::endl;
switch (nr){
case FD :


	if(detected)
	{
	state=1;
	detected=false;

	modules[LG]->work(wsk);//Logger runs send
	modules[WR]->work(&state);//Worker runs and sends HIGH state
//	modules[FD]->on=false; //Fdetect stops
	}
	else{
		sleep(2);
		detected=true;
		}

	break;
case LG:					//signal from Logger

	break;

case WR:					//signal from Worker
//TODO: sygnał do Fdetect? : STOP
	if(*(int*)(wsk)==2)//drzwi zamkniete
modules[FD]->on=false;
	else
		modules[FD]->on=true;
	break;
default :
;

}

return false;
}

Controller::Controller(int w,int h):
	cam_w(w),cam_h(h){
	modules[FD]=new Fdetect(this);
	modules[LG]=new Logger;
	modules[WR]=new Worker;
	detected=false;
	SigC.connect(bind(&Module::work,modules[WR],_1));
	//(*(this->modules[0])).SigW.connect(bind(&Controller::lunit,this,_1, _2));
	(*(this->modules[1])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
	(*(this->modules[2])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
}
Controller::~Controller(){
	delete  [] modules;
}
