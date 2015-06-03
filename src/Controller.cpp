/*
 * Controller.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "main.hpp"
bool Controller::lunit(int nr,void* wsk){
	int state= -1;
	std::cout<<"CONTROLLER ZAPIS"<<"RECEIVED SIGNAL :" << nr<<std::endl;
switch (nr){
case 0 :			   //signal from Fdetect
	state=1;
	modules[1]->work(wsk);//Logger runs
	modules[2]->work(&state);//Worker runs
if(wsk)	{
	//printf (" wartosc a = %d",*((int*)wsk)	);
}
	break;
case 1:					//signal from Logger

	break;

case 2:					//signal from Worker

	break;
default :
;

}

return false;
}

Controller::Controller(){
	modules[0]=new Fdetect(this);
	modules[1]=new Logger;
	modules[2]=new Worker;
	//(*(this->modules[0])).SigW.connect(bind(&Controller::lunit,this,_1, _2));
	(*(this->modules[1])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
	(*(this->modules[2])).SigW.connect(bind(&Controller::lunit,this,_1 , _2));
}
