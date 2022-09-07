#include "channel.h"

Channel::Channel(int client_group) : kClientGroup_(client_group) {
	serviced_client_ = nullptr;
}

int Channel::GetClientGroup() {
	return kClientGroup_;
}

void Channel::AddClient(Client* client) {
	serviced_client_ = client;
}

bool Channel::IsFree() {
	if (serviced_client_ == nullptr) return true;
	else return false;
}

void Channel::Release() {
	serviced_client_ = nullptr;
}

Client* Channel::GetClient() {
	return serviced_client_;
}