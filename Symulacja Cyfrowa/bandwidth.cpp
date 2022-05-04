#include "bandwidth.h"
#include <utility>
Bandwidth::Bandwidth(int l_a, int k_a, int p_a) : l_amount(l_a), k_amount(k_a), p_amount(p_a) {
	int u3_channel_amount = k_amount - p_amount - l_amount;
	for (int i = 0; i < p_amount; i++) {
		channels[i] = new Channel(1);
	}
	for (int i = p_amount; i < u3_channel_amount; i++) {
		channels[i] = new Channel(3);
	}
	for (int i = k_amount - l_amount; i < k_amount; i++) {
		channels[i] = new Channel(2);
	}
}

bool Bandwidth::add_to_channel(Client* c) {
	std::pair <int, int> group_indexes(0, 0);
	if (c->get_group() == 1) {
		group_indexes.first = 0;
		group_indexes.second = p_amount;
	}
	else if ((c->get_group() == 2)) {
		group_indexes.first = k_amount - l_amount;
		group_indexes.second = k_amount;
	}
	else {
		group_indexes.first = p_amount;
		group_indexes.second = k_amount - p_amount - l_amount;
	}
	for (int i = group_indexes.first; i < group_indexes.second; i++) {
		if (channels[i]->is_free()) {
			channels[i]->add_client(c);
			if (c->get_group() != 1) return true;
		}
	}
	if (c->get_group() == 1) return true;
	else return false;
}

void Bandwidth::clear_radar() {
	for (int i = 0; i < p_amount; i++) {
		channels[i]->release();
	}
}

void Bandwidth::remove_user(Client* c) {
	for (int i = p_amount - 1; i < k_amount; i++) {
		if (channels[i]->get_client() == c) {
			channels[i]->release();
			return;
		}
	}
}

void Bandwidth::clear() {
	for (int i = 0; i < 20; i++) {
		if (!channels[i]->is_free()) channels[i]->release();
	}
}