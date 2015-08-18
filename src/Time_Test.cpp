/*
 * Time_Test.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: fero
 */
#include "main.hpp"
using namespace std;
using namespace chrono;

void Time_Test::add(Module **pointer){
	//ptr=pointer;
int i;
	for (i=0; i<3; i++)
		wektor.push_back(pointer[i]);
	module_nr=i;
	std::cout<<"\n Dodano "<<module_nr<< " moduły"<<std::endl;
}



bool Time_Test::measure_time(){


	printf("Start testów czasowych \n");
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2 ;
	duration<double>  time_span,total_time;
	std::vector <std::chrono::duration<double>> times;

		for (int i=0; i<module_nr; ++i){
			 t1 = high_resolution_clock::now();
			 assert(! wektor[i]->work());
			 t2 = high_resolution_clock::now();
			 time_span  = duration_cast<nanoseconds>(t2 - t1);
			 times.push_back(time_span);
			 total_time += time_span;
		  }

		  for (int i=0; i<3; i++)
		  	std::cout<<"Czas działania modułu "<<wektor[i]->name+"\t"<< duration_cast<nanoseconds>(times[i]).count()<<std::endl;

		  std::cout << "Total time " << duration_cast<milliseconds>(total_time).count()<< " miliseconds.";
		  std::cout << std::endl;
	return 0;
}
