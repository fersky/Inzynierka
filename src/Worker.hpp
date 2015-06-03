/*
 * Worker.hpp
 *
 *  Created on: Jun 3, 2015
 *      Author: fero
 */

#ifndef WORKER_HPP_
#define WORKER_HPP_



class Worker : public Module{
public:
	Worker(){name="Worker_module";

	}
	bool work(void*){
		std::cout<<"WORKER RUNNING"<<std::endl;

	}
	~Worker(){};
};


#endif /* WORKER_HPP_ */
