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
/*	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	if(pthread_create(&tid,&attr,detector,NULL)){
std::cout<<"BLAD TWORZENIA WATKU"<<std::endl;

}
*/
#ifdef TIME_TEST

	Time_Test test;
	Controller k;
    Module *ptr []={k.modules[FD],k.modules[WR], k.modules[LG],NULL};
	test.add(ptr);
	test.measure_time(atoi(argv[1]));
	test.display_results();
<<<<<<< HEAD
=======

>>>>>>> 60c89a96216ab0c2086ea40dd6ee8575ecb81f68
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
	;
#endif
	//	SigW(2,NULL);

}
}


