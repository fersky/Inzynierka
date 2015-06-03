/*
 * Module.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef MODULE_HPP_
#define MODULE_HPP_
#include "main.hpp"
class Module{
public:
	std::string name;
	virtual bool work(void*wsk=0)=0;
	virtual ~Module(){};
	boost::signal<bool(int nr,void* wsk)> SigW;
};



#endif /* MODULE_HPP_ */
