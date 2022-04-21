#include "client.h"

Client::Client(int g, float s_t) : group(g), service_time(s_t) {}

int Client::get_group() {
	return group;
}

int Client::get_service_time() {
	return service_time;
}