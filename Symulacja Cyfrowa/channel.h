#ifndef CHANNEL_H
#define CHANNEL_H
#include "client.h"
class Channel
{
public:
	Channel(int client_group);
	int GetClientGroup();
	void AddClient(Client *client);
	bool IsFree();
	void Release(bool kicked = false);
	Client* GetClient();
private:
	Client* serviced_client_;
	const int kClientGroup_;
};

#endif
