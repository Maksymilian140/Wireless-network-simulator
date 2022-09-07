#include "bandwidth.h"
#include <utility>
#include <iostream>
#include <spdlog/spdlog.h>
Bandwidth::Bandwidth(int l_amount, int p_amount, int k_amount) : kLAmount_(l_amount), kPAmount_(p_amount), kKAmount_(k_amount) {
	int u3_channel_amount = k_amount - l_amount;
	for (int i = 0; i < p_amount; i++) {
		channels_[i] = new Channel(1);
	}
	for (int i = p_amount; i < u3_channel_amount; i++) {
		channels_[i] = new Channel(3);
	}
	for (int i = u3_channel_amount; i < k_amount; i++) {
		channels_[i] = new Channel(2);
	}
}

bool Bandwidth::AddToChannel(Client* client) {
	std::pair <int, int> group_indexes(0, 0);
	if (client->GetGroup() == 1) {
		group_indexes.first = 0;
		group_indexes.second = kPAmount_;
	}
	else if ((client->GetGroup() == 2)) {
		group_indexes.first = kKAmount_ - kLAmount_;
		group_indexes.second = kKAmount_;
	}
	else {
		group_indexes.first = kPAmount_;
		group_indexes.second = kKAmount_ - kLAmount_;
	}
	for (int i = group_indexes.first; i < group_indexes.second; i++) {
		if (channels_[i]->IsFree()) {
			channels_[i]->AddClient(client);
			if (client->GetGroup() != 1) return true;
		}
	}
	if (client->GetGroup() == 1) return true;
	else return false;
}

void Bandwidth::ClearRadar() {
	for (int i = 0; i < kPAmount_; i++) {
		channels_[i]->Release();
	}
}

void Bandwidth::RemoveUser(Client* client) {
	for (int i = kPAmount_ - 1; i < kKAmount_; i++) {
		if (channels_[i]->GetClient() == client) {
			channels_[i]->Release();
			return;
		}
	}
}

void Bandwidth::Clear() {
	for (int i = 0; i < 20; i++) {
		if (!channels_[i]->IsFree()) channels_[i]->Release();
	}
}

void Bandwidth::Print() {
	std::string bottom_line = "#      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #\n";
	std::string top_line = "############################################################CHANNELS#########################################################################\n";
	top_line += "#      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #      #\n";
	bottom_line += "|###############U1#################|###############U3#################|###################################U2################################|\n";
	std::string printed_bandwidth = "";
	char group = '0';
	for (int i = 0; i < 20; i++) {
		if (channels_[i]->GetClient() != nullptr) {
			group = static_cast<char>(channels_[i]->GetClientGroup() + 48);
			printed_bandwidth += "#  U";
			printed_bandwidth += group;
			printed_bandwidth += "  ";
		}
		else
			printed_bandwidth += "#      ";
	}
	printed_bandwidth += "#\n";
	spdlog::debug('\n' + top_line + printed_bandwidth + bottom_line);
}