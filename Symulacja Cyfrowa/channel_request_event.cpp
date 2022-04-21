#include "channel_request_event.h"
#include "end_of_service_event.h"

ChannelRequestEvent::ChannelRequestEvent(std::chrono::high_resolution_clock::time_point e_t, Network* n, Buffer* bu, Bandwidth* ba):Event(e_t, n), buffer(bu), bandwidth(ba){}

void ChannelRequestEvent::execute() {
	// checking if there is available channel
	Client* client = buffer->get_first();
	bool is_added = bandwidth->add_to_channel(client);
	// if there is then remove client from buffer and plan end of service event for him
	if (is_added) {
		buffer->pop();
		std::chrono::high_resolution_clock::time_point event_t = std::chrono::high_resolution_clock::now();
		event_t += std::chrono::microseconds(client->get_service_time());
		Event* service_event = new EndOfServiceEvent(event_t, network);
		event_list.insert(service_event);
	}
	// ether way plan next channel request event
	std::chrono::high_resolution_clock::time_point event_t = std::chrono::high_resolution_clock::now();
	event_t += std::chrono::microseconds(request_frequency);
	Event* next_request_event = new ChannelRequestEvent(event_t, network, buffer, bandwidth);
	event_list.insert(next_request_event);
}