#include "user_activation_event.h"
#include "user_end_of_service_event.h"

UserActivationEvent::UserActivationEvent(float event_time, Network* network) :Event(event_time, network) {}

void UserActivationEvent::execute() {
	// draw group number and generate new user and add him to bandwidth
	int group = rand() % 2 + 2;
	Client* user = network->generate_client(group);
	bool is_added = network->add_to_bandwidth(user);
	// if user succesfuly was added to the channel then plan end of service event for him
	if (is_added) {
		float event_t = (rand() % 5000 + 1000) + network->clock;
		Event* next_request_event = new UserEndOfServiceEvent(event_t, network, user);
		event_list.insert(next_request_event);
	}
	else {
		// if buffer is occupied then drop the user else add him to the buffer
		if (network->buffer_is_occupied()) delete user;
		else network->add_to_buffer(user);
		// plan next user activation event
		float event_t = (rand() % 7000 + 1000) + network->clock;
		Event* next_request_event = new UserActivationEvent(event_t, network);
		event_list.insert(next_request_event);
	}
}