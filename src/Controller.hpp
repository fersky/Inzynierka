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
	int cam_w,cam_h;
	boost::signal <bool(void *wsk)>SigC;
Controller(int w=320,int h=240);
//Controller();
bool detected;
	Module * modules[3];
 bool lunit(int nr,void* wsk);

 ~Controller();
};


#endif /* CONTROLLER_HPP_ */
