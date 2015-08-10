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
	Worker();
	bool work(void*);
	~Worker(){};
//	void * detector(void *param);
};


#endif /* WORKER_HPP_ */
