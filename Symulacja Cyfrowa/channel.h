#ifndef CHANNEL_H
#define CHANNEL_H
#include "client.h"
class Channel
{
public:
	Channel(int c_g);
	int get_client_group();
	void add_client(Client *c);
	bool is_free();
	void release();
private:
	Client* serviced_client;
	const int client_group;
};

#endif
