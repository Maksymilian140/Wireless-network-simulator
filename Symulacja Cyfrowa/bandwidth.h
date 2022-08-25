#ifndef BANDWIDTH_H
#define BANDWIDTH_H
#include <utility>
#include "channel.h"
class Bandwidth
{
public:
	Bandwidth(int l_amount, int p_amount, int k_amount);
	bool AddToChannel(Client* client, int new_group = 0, int attempt = 1);
	std::pair <int, int> GroupToIndexes(int group);
	bool IsFull(int group);
	void ClearRadar();
	void RemoveUser(Client* client);
	void Clear();
	void Print();
private:
	const int kLAmount_, kPAmount_, kKAmount_;
	Channel* channels_[20];
};

#endif

