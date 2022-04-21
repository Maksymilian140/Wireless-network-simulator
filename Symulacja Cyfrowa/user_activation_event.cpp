#include "user_activation_event.h"

UserActivationEvent::UserActivationEvent(std::chrono::high_resolution_clock::time_point e_t, Network* n) :Event(e_t, n) {}

void UserActivationEvent::execute() {
	// draw group number and generate new user and add him to bandwidth
	int group = rand() % 2 + 2;
	Client* user = network->generate_client(group);
	bool is_added = network->add_to_bandwidth(user);
	// if user succesfuly was added to the channel then plan end of service event for him
	if (is_added) {
		std::chrono::high_resolution_clock::time_point event_t = std::chrono::high_resolution_clock::now();
		event_t += std::chrono::microseconds(rand() % 5000 + 1000);
		Event* next_request_event = new UserEndOfServiceEvent(event_t, network);
		event_list.insert(next_request_event);
	}
	else {
		network->add
	}
}