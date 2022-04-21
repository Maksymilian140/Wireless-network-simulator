#ifndef NETWORK_H
#define NETWORK_H
#include "client.h"
#include "buffer.h"
#include "channel.h"
#include "bandwidth.h"
#include <ctime>

class Network {
public:
	Network(int l_a, int p_a, int k_a, int s, float t_t);
	Client* generate_client(int group);
	Client* get_first_from_buffer();
	bool add_to_bandwidth(Client* c);
	Client* buffer_pop();
	void bandwidth_clear_radar();
private:
	Bandwidth* bandwidth;
	Buffer* buffer;
	time_t main_time, u1_time, u2_time, u3_time;

};

#endif