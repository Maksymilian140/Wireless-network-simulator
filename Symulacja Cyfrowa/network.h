#ifndef NETWORK_H
#define NETWORK_H
#include "client.h"
#include "buffer.h"
#include "channel.h"
#include "bandwidth.h"
#include <string>
#include <list>
#include <utility>

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
	int get_ratio();
	std::string get_clock();
	std::list<std::pair<double, std::string>> GetBandwidthUsageList();
	void SaveBandwidthStat();
	void UpdateBandwidthStat();
	void UpdateUserStat(int group);
	void UpdateUserLostStat(int group);
	void LogBlockProbability();
	int clock_;
private:
	Bandwidth* bandwidth_;
	Buffer* buffer_;
	int u2_total_ = 0, u3_total_ = 0, u2_lost_ = 0, u3_lost_ = 0;
	std::list<std::pair<double, std::string>> avg_bandwidth_usage_stat_;

};

#endif