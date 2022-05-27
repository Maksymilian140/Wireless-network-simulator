#ifndef BUFFER_H
#define BUFFER_H
#include <queue>
#include "client.h"
class Buffer
{
public:
	Buffer(int size, float try_time);

	void Add(Client* client);
	Client* Pop();
	Client* get_first();
	bool is_occupied();
	void Clear();
	void Print();
private:
	std::queue<Client*>queue_of_clients_;
	const int kSize_;
	const float	kTryTime_;
};

#endif
