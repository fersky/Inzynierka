/*
 * Time_Test.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: fero
 */
#include "main.hpp"
using namespace std;
using namespace chrono;
<<<<<<< HEAD
int c=0;
=======
duration<double>  time_span,total_time;
	vector <duration<double>> times;

>>>>>>> dafde4d2a81bb548889f69d781dfc8cd43925a4d
void Time_Test::add(Module **pointer){
int i;
	for (i=0; pointer[i]!= NULL; ++i)
		wektor.push_back(pointer[i]);
	module_nr=i;
	std::cout<<"\nAdded "<<module_nr<< " modules"<<std::endl;
}



bool Time_Test::measure_time(int b){


	printf("Start of time tests \n");
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2 ;
<<<<<<< HEAD
	duration<double>  time_span,total_time;
	std::vector <std::chrono::duration<double>> times;
printf("\nIlosc iteracji %d",b);
=======



>>>>>>> dafde4d2a81bb548889f69d781dfc8cd43925a4d
		for (int i=0; i<module_nr; ++i){
			 t1 = high_resolution_clock::now();
c=0;
while(c<b){	
		 assert(! wektor[i]->work());
c++;
}	
		 t2 = high_resolution_clock::now();
			 time_span  = duration_cast<nanoseconds>(t2 - t1);
			 times.push_back(time_span);
			 total_time += time_span;
		  }

<<<<<<< HEAD
		  for (int i=0; i<3; i++)
		  	std::cout<<"Czas działania modułu "<<wektor[i]->name+"\t"<< duration_cast<nanoseconds>(times[i]).count()/b<<std::endl;

		  std::cout << "Total time " << duration_cast<milliseconds>(total_time).count()/b<< " miliseconds.";
		  std::cout << std::endl;
=======

>>>>>>> dafde4d2a81bb548889f69d781dfc8cd43925a4d
	return 0;
}
void Time_Test::display_results(){
	 for (int i=0; i<3; i++)
			  std::cout<<"Execution time of module "<<wektor[i]->name+"\t : "<< duration_cast<nanoseconds>(times[i]).count()<<" ns"<<std::endl;
			  std::cout << "Total time : " << duration_cast<milliseconds>(total_time).count()<< " ms"<<endl;
			  std::cout << std::endl;
}
