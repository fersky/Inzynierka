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

public:
	void add(Module **);
<<<<<<< HEAD
	bool measure_time(int b);
=======
	bool measure_time();
	void display_results();
>>>>>>> dafde4d2a81bb548889f69d781dfc8cd43925a4d
};



#endif /* TIME_TEST_HPP_ */
