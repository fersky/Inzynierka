/*
 * Controller.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_
#include "main.hpp"

class Controller{
public:
	typedef boost::signals::connection conn;
	int cam_w,cam_h,latency;
	boost::signal <bool(void *wsk)>SigC;
Controller(int w=320,int h=240,int l=2000);
//Controller();
bool detected;
	Module * modules[3];
 bool logicUnit(int nr,void* wsk);

 ~Controller();
private:
 conn c_obd;
 conn c_wor;
 conn c_log;
};


#endif /* CONTROLLER_HPP_ */
