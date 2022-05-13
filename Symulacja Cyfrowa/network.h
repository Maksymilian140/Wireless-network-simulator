#ifndef NETWORK_H
#define NETWORK_H
#include "client.h"
#include "buffer.h"
#include "channel.h"
#include "bandwidth.h"

class Network {
public:
	Network(int l_amount, int p_amount, int k_amount, int size, int try_time);
	Client* generate_client(int group);
	Client* get_first_from_buffer();
	bool add_to_bandwidth(Client* c);
	Client* buffer_pop();
	void bandwidth_clear_radar();
	bool buffer_is_occupied();
	void add_to_buffer(Client* c);
	void remove_from_bandwidth(Client* c);
	void initialize();
	int clock;
private:
	Bandwidth* bandwidth;
	Buffer* buffer;
};

#endif