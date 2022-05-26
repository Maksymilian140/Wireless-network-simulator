#include "user_activation_event.h"
#include "user_end_of_service_event.h"

UserActivationEvent::UserActivationEvent(float event_time, Network* network, EventList* event_list) :Event(event_time, network), event_list(event_list) {}

void UserActivationEvent::execute() {
	// draw group number and generate new user and add him to bandwidth
	int group = rand() % 2 + 2;
	spdlog::info("Time: " + std::to_string(network->clock) + " ##### U" + std::to_string(group) + " is generated\n");
	Client* user = network->generate_client(group);
	bool is_added = network->add_to_bandwidth(user);
	// if user succesfuly was added to the channel then plan end of service event for him
	if (is_added) {
		spdlog::info("Time: " + std::to_string(network->clock) + " ##### U" + std::to_string(user->get_group()) + " is added to channel\n");
		float event_t = (rand() % 5000 + 1000) + network->clock;
		Event* next_request_event = new UserEndOfServiceEvent(event_t, network, user);
		event_list->insert(next_request_event);
	}
	else {
		// if buffer is occupied then drop the user else add him to the buffer
		if (network->buffer_is_occupied()) delete user;
		else {
			spdlog::info("Time: " + std::to_string(network->clock) + " ##### U" + std::to_string(group) + " is added to buffer\n");
			network->add_to_buffer(user);
		}
	}
	network->bandwidth_print();
	network->buffer_print();
	// plan next user activation event
	float event_t = (rand() % 800 + 100) + network->clock;
	Event* next_request_event = new UserActivationEvent(event_t, network, event_list);
	event_list->insert(next_request_event);
}