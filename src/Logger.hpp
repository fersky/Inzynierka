/*
 * Logger.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include "main.hpp"
class Logger : public Module{
public:
	Logger();
	cv::Mat * frame;

	bool work(void* wsk);
	const std::string getcurdate();
	~Logger(){};
};



#endif /* LOGGER_HPP_ */
