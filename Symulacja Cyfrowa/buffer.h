#ifndef BUFFER_H
#define BUFFER_H
#include <queue>
#include "client.h"
class Buffer
{
public:
	Buffer(int s, float t_t);

	void add(Client*);
	Client* pop();
	Client* get_first();
private:
	std::queue<Client*>queue_of_clients;
	const int size;
	const float	try_time;
};

#endif
