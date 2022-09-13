#ifndef NETWORK_H
#define NETWORK_H
#include "client.h"
#include "buffer.h"
#include "channel.h"
#include "bandwidth.h"
#include "generator.h"
#include <string>
#include <list>
#include <utility>

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
	void Initialize(double lambda, int seed, int phase);
	void BandwidthPrint();
	void BufferPrint();
	int GetRatio();
	double GetLambda();
	int GetRadarChannelAmount();
	std::string GetClock();
	void SaveBlockProbStat();
	void UpdateBandwidthStat();
	void UpdateUserStat(int group);
	void UpdateUserLostStat(int group);
	void UpdateServicedUsersStat();
	void UpdateAllUsersStat();
	void DisplayBlockProbability();
	void DisplayServicedUsersStat();
	void DisplayBandwidthStat();
	double ReturnBlockProbability();
	double GenerateUserTime(double intensity);
	int clock_, phase_time_;
private:
	Bandwidth* bandwidth_;
	Buffer* buffer_;
	int u2_total_ = 0, u3_total_ = 0, u2_lost_ = 0, u3_lost_ = 0, u2_serviced_sum_ = 0, u3_serviced_sum_ = 0, stat_counter_ = 0, all_users_ = 0;
	double bandwidth_usage_counter_ = 0;
	double lambda_;
	UniformGenerator *user_time_generator_;
};

#endif