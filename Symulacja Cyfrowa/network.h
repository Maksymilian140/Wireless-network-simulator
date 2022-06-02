#ifndef NETWORK_H
#define NETWORK_H
#include "client.h"
#include "buffer.h"
#include "channel.h"
#include "bandwidth.h"
#include <string>

class Network {
public:
	Network(int l_amount, int p_amount, int k_amount, int size, int try_time);
	Client* GenerateClient(int group);
	Client* get_first_from_buffer();
	bool AddToBandwidth(Client* client);
	Client* BufferPop();
	void BandwidthClearRadar();
	bool is_buffer_occupied();
	void AddToBuffer(Client* client);
	void RemoveFromBandwidth(Client* client);
	void Initialize();
	void BandwidthPrint();
	void BufferPrint();
	std::string get_clock();
	int clock_;
private:
	Bandwidth* bandwidth_;
	Buffer* buffer_;
};

#endif