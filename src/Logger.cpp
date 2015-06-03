/*
 * Logger.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */
#include "Logger.hpp"

#include "main.hpp"
extern std::vector<cv::Rect> faces;
bool Logger::work(void* wsk){
	std::cout<<name<<" RUNNING"<<std::endl;
	std::ofstream log;
	frame = (cv::Mat*)(wsk);
	log.open("/var/www/html/log.txt",std::ios::out | std::ios::app);

	if(!log.is_open())
	  std::cout<<"BLAD ODCZYTU PLIKU LOGOW"<<std::endl;

	for(int i=0; i<faces.size();i++){

		//string index = to_string(i);
	    std::string name = getcurdate()+".jpg";
	    cv::Mat face(*frame,faces[i]);
	    std::string str(name);
	    size_t found= str.find_first_of(":");

	    while (found!=std::string::npos)
	     {
	       str[found]='_';
	       found=str.find_first_of(":",found+1);
	     }

	    log<<name<<std::endl;
	    std::string path;
	    path= "/var/www/html/faces/" + str;
	    printf("%s \n",path.c_str());

	    if( !imwrite(path,face))
	    	std::cout<<"BLAD ZAPISU OBRAZU DO PLIKU";

	}

return 0;
}

const std::string Logger::getcurdate(){
time_t t = time(0);
struct tm *now= localtime(&t);
char buf [30];

strftime(buf,sizeof(buf),"X%Y-%m-%d.%X",now);


return buf;
}

Logger::Logger(){name="LOGGER";}
