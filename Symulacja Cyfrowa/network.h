#ifndef NETWORK_H
#define NETWORK_H
#include "client.h"
#include "buffer.h"
#include "channel.h"
#include "bandwidth.h"
#include <ctime>

class Network {
public:
	Network();
private:
	Bandwidth bandwidth;
	Buffer buffer;
	int u1_time, u2u3_time;
	time_t main_time;

};

#endif