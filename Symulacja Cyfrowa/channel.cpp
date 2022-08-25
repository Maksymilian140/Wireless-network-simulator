#include "channel.h"

Channel::Channel(int client_group) : kClientGroup_(client_group) {
	serviced_client_ = nullptr;
}

int Channel::get_client_group() {
	if (serviced_client_ != nullptr) return serviced_client_->get_group();
}

void Channel::AddClient(Client* client) {
	serviced_client_ = client;
}

bool Channel::is_free() {
	if (serviced_client_ == nullptr) return true;
	else return false;
}

void Channel::Release() {
	serviced_client_ = nullptr;
}

Client* Channel::get_client() {
	return serviced_client_;
}