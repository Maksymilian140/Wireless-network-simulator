#ifndef CHANNEL_H
#define CHANNEL_H
#include "client.h"
class Channel
{
public:
	Channel(int client_group);
	int get_client_group();
	void AddClient(Client *client);
	bool is_free();
	void Release();
	Client* get_client();
private:
	Client* serviced_client_;
	const int kClientGroup_;
};

#endif
