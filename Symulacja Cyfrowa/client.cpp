#include "client.h"

Client::Client(int group, int service_time) : kGroup_(group), kServiceTime_(service_time) {}

int Client::GetGroup() {
	return kGroup_;
}

int Client::GetServiceTime() {
	return kServiceTime_;
}