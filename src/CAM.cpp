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
/** Function Headers */


/** Global variables */
vector<Rect> faces;



int main(){
	Controller k;
	k.modules[0]->work();
//	k.modules[1]
	return 0;
}



