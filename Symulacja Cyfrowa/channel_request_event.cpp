#include "channel_request_event.h"
#include "radar_end_of_service_event.h"

ChannelRequestEvent::ChannelRequestEvent(float event_time, Network* network):Event(event_time, network){}

void ChannelRequestEvent::execute() {
	// checking if there is available channel
	Client* client = network->get_first_from_buffer();
	bool is_added = network->add_to_bandwidth(client);
	// if there is then remove client from buffer and plan end of service event for him
	if (is_added) {
		network->buffer_pop();
		float event_t = client->get_service_time() + network->clock;
		Event* service_event;
		service_event = new RadarEndOfServiceEvent(event_t, network); 
		event_list.insert(service_event);
	}
	// ether way plan next channel request event
	float event_t = request_frequency + network->clock;
	Event* next_request_event = new ChannelRequestEvent(event_t, network);
	event_list.insert(next_request_event);
}