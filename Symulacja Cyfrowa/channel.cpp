#include "channel.h"
#include <spdlog/spdlog.h>

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

void Channel::Release(bool kicked) {
	if (kicked) spdlog::info("U" + std::to_string(serviced_client_->get_group()) + " is kicked out due to arrival of higher priority user\n");
	serviced_client_ = nullptr;
}

Client* Channel::get_client() {
	return serviced_client_;
}