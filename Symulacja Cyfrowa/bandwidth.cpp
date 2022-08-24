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

bool Bandwidth::AddToChannel(Client* client, int new_group, int attempt) {
	std::pair <int, int> group_indexes(0, 0);
	if (new_group == 0) new_group = client->get_group();
	if (new_group == 1) {
		group_indexes.first = 0;
		group_indexes.second = kPAmount_;
	}
	else if (new_group == 2) {
		group_indexes.first = kKAmount_ - kLAmount_;
		group_indexes.second = kKAmount_;
	}
	else {
		group_indexes.first = kPAmount_;
		group_indexes.second = kKAmount_ - kLAmount_;
	}
	for (int i = group_indexes.first; i < group_indexes.second; i++) {
		if (channels_[i]->get_client_group() > client->get_group()) channels_[i]->Release();
		if (channels_[i]->is_free()) {
			channels_[i]->AddClient(client);
			if (client->get_group() != 1) return true;
		}
	}
	if (client->get_group() == 1) return true;
	else {
		if (client->get_group() == 2) {
			switch (attempt) {
				case 1:
					AddToChannel(client, 3, ++attempt);
					break;
				case 2:
					AddToChannel(client, 1, ++attempt);
					break;
				case 3:
					return false;
			}
		}
		if (client->get_group() == 3) {
			switch (attempt) {
				case 1:
					AddToChannel(client, 1, ++attempt);
					break;
				case 2:
					AddToChannel(client, 2, ++attempt);
					break;
				case 3:
					return false;
			}
		}
	}
}

void Bandwidth::ClearRadar() {
	for (int i = 0; i < kPAmount_; i++) {
		channels_[i]->Release();
	}
}

void Bandwidth::RemoveUser(Client* client) {
	for (int i = kPAmount_ - 1; i < kKAmount_; i++) {
		if (channels_[i]->get_client() == client) {
			channels_[i]->Release();
			return;
		}
	}
}

void Bandwidth::Clear() {
	for (int i = 0; i < 20; i++) {
		if (!channels_[i]->is_free()) channels_[i]->Release();
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
		if (channels_[i]->get_client() != nullptr) {
			group = static_cast<char>(channels_[i]->get_client_group() + 48);
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