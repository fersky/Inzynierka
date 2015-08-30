/*
 * Controller.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"

bool Controller::logicUnit(int nr,void* wsk){
	int state= -1;
	int * notification;
	std::cout<<"CONTROLLER "<<"RECEIVED SIGNAL : " << nr<<std::endl;
	switch (nr){
	case FD :

		/*
	if(detected)
	{
	state=1;
	detected=false;

	modules[LG]->work(wsk);//Logger runs send
	modules[WR]->work(&state);//Worker runs and sends HIGH state
//	modules[FD]->on=false; //Object_Detection stops
	}
	else{

		usleep(latency*1000);
		detected=true;
		}
		 */if(detected){
			 printf("\n po walidacji \n");
			 detected=false;
			 modules[FD]->enabled=false;
			 modules[LG]->work(wsk);
			 wsk=0;


		 }
		 else{
			 printf("\n pierwszy sygnał\n");
			 usleep(4000*1000);
			 detected=true;
		 }

		 break;
	case LG:					//signal from Logger
		modules[FD]->enabled=true;
		printf("OBD enabled, running OBD->work()");
		//modules[FD]->work();
		break;

	case WR:
		//signal from Worker
		notification = static_cast<int*>(wsk);
		//TODO: sygnał do Object_Detection? : STOP
		if(*notification==2)//drzwi zamkniete
			modules[FD]->enabled=false;
		else
			modules[FD]->enabled=true;
		break;
	default :
		;

	}

	return false;
}

Controller::Controller(int w,int h,int l):
							cam_w(w),cam_h(h),latency(l){
	modules[FD]=new Object_Detection(this);
	modules[LG]=new Logger;
	modules[WR]=new Worker;
	detected=false;
	//sygnał do workera definicja
	SigC.connect(bind(&Module::work,modules[WR],_1));
	//(*(this->modules[0])).SigW.connect(bind(&Controller::logicUnit,this,_1, _2));
	//sloty obiektów object detection i logger
	c_obd = (*(this->modules[FD])).SigW.connect(bind(&Controller::logicUnit,this,_1, _2));
	c_log = (*(this->modules[LG])).SigW.connect(bind(&Controller::logicUnit,this,_1 , _2));
	c_wor = (*(this->modules[WR])).SigW.connect(bind(&Controller::logicUnit,this,_1 , _2));
}
Controller::~Controller(){
	delete  [] modules;
}
