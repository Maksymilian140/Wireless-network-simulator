#ifndef BANDWIDTH_H
#define BANDWIDTH_H
#include <utility>
#include "channel.h"
class Bandwidth
{
public:
	Bandwidth(int l_amount, int p_amount, int k_amount);
	bool AddToChannel(Client* client);
	std::pair <int, int> GroupToIndexes(int group);
	bool IsFull(int group);
	void ClearRadar();
	void RemoveUser(Client* client);
	void Clear();
	void Print();
	double GetUsage();
	int GetSize();
	int GetRadarBandwidthSize();
	void UpdateKickedStat(int group);
	std::pair<int, int> GetKickedStat();
	int CountServicedUsers(int group);
	void SetPhase(int phase);
private:
	const int kLAmount_, kPAmount_, kKAmount_;
	Channel* channels_[20];
	int u2_kicked_ = 0, u3_kicked_ = 0, phase_time_;
};

#endif

