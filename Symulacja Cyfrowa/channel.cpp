#include "channel.h"

Channel::Channel(int client_group) : client_group(client_group) {
	serviced_client = nullptr;
}

int Channel::get_client_group() {
	return client_group;
}

void Channel::add_client(Client* c) {
	serviced_client = c;
}

bool Channel::is_free() {
	if (serviced_client == nullptr) return true;
	else return false;
}

void Channel::release() {
	serviced_client = nullptr;
}

Client* Channel::get_client() {
	return serviced_client;
}