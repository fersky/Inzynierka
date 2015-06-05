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
	boost::signal <bool(void *wsk)>SigC;
Controller();
bool detected;
	Module * modules[3];
 bool lunit(int nr,void* wsk);

 ~Controller();
};


#endif /* CONTROLLER_HPP_ */
