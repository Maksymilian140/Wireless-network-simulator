#include "channel_request_event.h"
#include "radar_end_of_service_event.h"

ChannelRequestEvent::ChannelRequestEvent(std::chrono::high_resolution_clock::time_point e_t, Network* n):Event(e_t, n){}

void ChannelRequestEvent::execute() {
	// checking if there is available channel
	Client* client = network->get_first_from_buffer();
	bool is_added = network->add_to_bandwidth(client);
	// if there is then remove client from buffer and plan end of service event for him
	if (is_added) {
		network->buffer_pop();
		std::chrono::high_resolution_clock::time_point event_t = std::chrono::high_resolution_clock::now();
		event_t += std::chrono::microseconds(client->get_service_time());
		Event* service_event;
		if(client->get_group() == 1) service_event = new RadarEndOfServiceEvent(event_t, network);
		else 
		event_list.insert(service_event);
	}
	// ether way plan next channel request event
	std::chrono::high_resolution_clock::time_point event_t = std::chrono::high_resolution_clock::now();
	event_t += std::chrono::microseconds(request_frequency);
	Event* next_request_event = new ChannelRequestEvent(event_t, network);
	event_list.insert(next_request_event);
}