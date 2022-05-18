#ifndef BANDWIDTH_H
#define BANDWIDTH_H
#include "channel.h"
class Bandwidth
{
public:
	Bandwidth(int l_amount, int p_amount, int k_amount);
	bool add_to_channel(Client* c);
	void clear_radar();
	void remove_user(Client* c);
	void clear();
	void print();
private:
	const int l_amount, p_amount, k_amount;
	Channel* channels[20];
};

#endif

