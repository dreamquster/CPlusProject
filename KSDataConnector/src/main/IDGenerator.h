#ifndef CTP_ID_GENERATOR_H
#define CTP_ID_GENERATOR_H

#include <pthread.h>

namespace ctp {

class IDGenerator
{
public:
	IDGenerator();
	~IDGenerator();
	int NextID();
private:
	int _idHolder;
	mutable pthread_mutex_t _idMutex; 
};

}

#endif