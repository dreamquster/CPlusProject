#include "IDGenerator.h"
#include <climits>
#include <iostream>

namespace ctp {

IDGenerator::IDGenerator():_idHolder(1)
{
	pthread_mutex_init(&_idMutex, NULL);
}

IDGenerator::~IDGenerator()
{
	pthread_mutex_destroy(&_idMutex); 
}

int IDGenerator::NextID()
{
	pthread_mutex_lock(&_idMutex); 
	if (_idHolder == INT_MAX) {
		std::cout << "Rolling ID in IDGenerator" << std::endl;
		_idHolder = 1;
	}
	int newID = _idHolder++;
	pthread_mutex_unlock(&_idMutex); 
	return newID;
}

}