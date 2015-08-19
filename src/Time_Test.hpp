/*
 * Time_Test.hpp
 *
 *  Created on: Aug 18, 2015
 *      Author: fero
 */
#include "main.hpp"

#ifndef TIME_TEST_HPP_
#define TIME_TEST_HPP_


class Time_Test{
private:
	int module_nr;
	std::vector <Module*> wektor;
	int N;

public:
	void add(Module **);
	void measure_time(int n);
	void display_results();
};



#endif /* TIME_TEST_HPP_ */
