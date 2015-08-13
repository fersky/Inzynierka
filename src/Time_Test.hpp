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
	void measure_time(int b);
	bool measure_time();
=======
	void measure_time(int n);
>>>>>>> 60c89a96216ab0c2086ea40dd6ee8575ecb81f68
	void display_results();
};



#endif /* TIME_TEST_HPP_ */
