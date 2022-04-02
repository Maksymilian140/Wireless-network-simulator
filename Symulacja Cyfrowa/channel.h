#ifndef CHANNEL_H
#define CHANNEL_H
#include "client.h"
class Channel
{
public:
	Channel(int c_g);
private:
	Client* serviced_client;
	const int client_group;
};

#endif
