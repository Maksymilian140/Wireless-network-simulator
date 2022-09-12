#include "channel.h"
#include <spdlog/spdlog.h>

Channel::Channel(int client_group) : kClientGroup_(client_group) {
	serviced_client_ = nullptr;
}

int Channel::GetClientGroup() {
	if (serviced_client_ != nullptr) return serviced_client_->GetGroup();
}

void Channel::AddClient(Client* client) {
	serviced_client_ = client;
}

bool Channel::IsFree() {
	if (serviced_client_ == nullptr) return true;
	else return false;
}

void Channel::Release(bool kicked) {
	if (kicked) spdlog::debug("U" + std::to_string(serviced_client_->GetGroup()) + " is kicked out due to arrival of higher priority user\n");
	serviced_client_ = nullptr;
}

Client* Channel::GetClient() {
	return serviced_client_;
}