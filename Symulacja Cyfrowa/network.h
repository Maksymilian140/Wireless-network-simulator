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
	Client* GetFirstFromBuffer();
	bool AddToBandwidth(Client* client);
	Client* BufferPop();
	void BandwidthClearRadar();
	bool IsBufferOccupied();
	void AddToBuffer(Client* client);
	void RemoveFromBandwidth(Client* client);
	void Initialize();
	void BandwidthPrint();
	void BufferPrint();
	void UpdateUserStat(int group);
	std::string GetClock();
	int GetRatio();
	int clock_;
private:
	Bandwidth* bandwidth_;
	Buffer* buffer_;
	int u2_total_ = 0, u3_total_ = 0;
};

#endif