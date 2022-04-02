#ifndef BUFFER_H
#define BUFFER_H
#include <queue>
#include "client.h"
class Buffer
{
public:
	Buffer(int s, int t_t);
private:
	std::queue<Client*>queue_of_clients;
	const int size, try_time;
};

#endif
