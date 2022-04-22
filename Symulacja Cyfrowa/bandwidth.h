#ifndef BANDWIDTH_H
#define BANDWIDTH_H
#include "channel.h"
class Bandwidth
{
public:
	Bandwidth(int l_a, int p_a, int k_a);
	bool add_to_channel(Client* c);
	void clear_radar();
	void remove_user(Client* c);
private:
	const int l_amount, p_amount, k_amount;
	Channel* channels[20];
};

#endif

