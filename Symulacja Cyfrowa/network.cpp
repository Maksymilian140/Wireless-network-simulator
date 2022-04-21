#include "Network.h"

Network::Network(int l_a, int p_a, int k_a, int s, float t_t){
	bandwidth = new Bandwidth(l_a, p_a, k_a);
	buffer = new Buffer(s, t_t);
}

Client* Network::generate_client(int group) {
	float service_time = 0;
	if (group == 1) service_time = 0.01;
	else service_time = rand() % 5 + 1;
	Client* new_client = new Client(group, service_time);
	return new_client;
}

Client* Network::get_first_from_buffer() {
	return buffer->get_first();
}

bool Network::add_to_bandwidth(Client* c) {
	return bandwidth->add_to_channel(c);
}

Client* Network::buffer_pop() {
	return buffer->pop();
}

void Network::bandwidth_clear_radar() {
	bandwidth->clear_radar();
}