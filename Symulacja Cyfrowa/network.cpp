#include "network.h"
#include "event.h"

Network::Network(int l_amount, int p_amount, int k_amount, int size, int try_time) {
	bandwidth = new Bandwidth(l_amount, p_amount, k_amount);
	buffer = new Buffer(size, try_time);
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

bool Network::buffer_is_occupied() {
	return buffer->is_occupied();
}

void Network::add_to_buffer(Client* c) {
	buffer->add(c);
}

void Network::remove_from_bandwidth(Client* c) {
	bandwidth->remove_user(c);
	delete c;
}

void Network::initialize() {
	bandwidth->clear();
	buffer->clear();
}