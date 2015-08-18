//============================================================================
// Name        : CAM.cpp
// Author      : Fero
// Version     : 1.1
// Copyright   : Your copyright notice
// Description : Fast, Intelligent Camera with Ethernet Interface
//============================================================================


#include "main.hpp"


using namespace std;
using namespace boost;
using namespace cv;
using namespace chrono;


vector<Rect> faces;
extern cv::Mat test_frame;
void * detector(void *);


int main(int argc, char **argv){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	if(pthread_create(&tid,&attr,detector,NULL)){
std::cout<<"BLAD TWORZENIA WATKU"<<std::endl;
}
#ifdef TIME_TEST

	Time_Test test;
	Controller k;
	Module *ptr [3]={k.modules[FD],k.modules[WR], k.modules[LG]};
	test.add(ptr);
	test.measure_time();
	//blok czasowy
	/*
	Controller k;
	Module *ptr [3]={k.modules[FD],k.modules[WR], k.modules[LG]};
	std::vector <Module*> wektor;
	std::vector <duration<double>> times;
	printf("Start testów czasowych \n");
	for (int i=0; i<3; i++)
		wektor.push_back(ptr[i]);
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2 ;
	duration<double>  time_span,total_time;
	  for (int i=0; i<3; ++i){
		   t1 = high_resolution_clock::now();
		 assert(! wektor[i]->work());
		 t2 = high_resolution_clock::now();
		 time_span  = duration_cast<nanoseconds>(t2 - t1);
		 times.push_back(time_span);
total_time += time_span;
	  }

	  for (int i=0; i<3; i++)
	  	std::cout<<"Czas działania modułu "<<wektor[i]->name+"\t"<< duration_cast<nanoseconds>(times[i]).count()<<endl;

	  std::cout << "Total time " << duration_cast<milliseconds>(total_time).count()<< " miliseconds.";
	  std::cout << std::endl;

	  //koniec bloku czasowego
*/
#else


	if(argc < 3)
	{
		Controller C;
		C.modules[0]->work();

	}
	else{
	Controller C(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
	C.modules[0]->work();

	}
#endif

	return 0;
}

void* detector(void * param){
	std::cout<<"running detector thread"<<std::endl;
while(1){

#ifdef BRD_BUILD
	if(!digitalRead(1)) //Przyjęto LOW na pinie GPIO1 jako stan drzwi zamknięty
#endif
	//	SigW(2,NULL);

}
}


