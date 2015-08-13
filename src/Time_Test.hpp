/*
 * Time_Test.hpp
 *
 *  Created on: Aug 18, 2015
 *      Author: fero
 */

#ifndef TIME_TEST_HPP_
#define TIME_TEST_HPP_
#include "main.hpp"

using namespace std;


class Time_Test{
private:
	int module_nr;
	Module **ptr;
	std::vector <Module*> wektor;

public:
	void add(Module **);
	bool measure_time(int b);
};



#endif /* TIME_TEST_HPP_ */
