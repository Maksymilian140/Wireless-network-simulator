#include "client.h"

Client::Client(int group, float service_time) : group(group), service_time(service_time) {}

int Client::get_group() {
	return group;
}

int Client::get_service_time() {
	return service_time;
}