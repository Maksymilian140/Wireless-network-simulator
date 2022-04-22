#include "channel.h"

Channel::Channel(int c_g) : client_group(c_g) {}

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
	delete serviced_client;
	serviced_client = nullptr;
}

Client* Channel::get_client() {
	return serviced_client;
}