#ifndef BUFFER_H
#define BUFFER_H
#include <queue>
#include "client.h"
class Buffer
{
public:
	Buffer(int size, float try_time);

	void add(Client*);
	Client* pop();
	Client* get_first();
	bool is_occupied();
	void clear();
private:
	std::queue<Client*>queue_of_clients;
	const int size;
	const float	try_time;
};

#endif
