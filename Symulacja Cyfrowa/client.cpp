#include "client.h"

Client::Client(int group, int service_time) : kGroup_(group), kServiceTime_(service_time) {}

int Client::get_group() {
	return kGroup_;
}

int Client::get_service_time() {
	return kServiceTime_;
}