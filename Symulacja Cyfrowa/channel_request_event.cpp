#include "channel_request_event.h"
#include "user_end_of_service_event.h"

ChannelRequestEvent::ChannelRequestEvent(float event_time, Network* network, EventList* event_list):Event(event_time, network), event_list_(event_list) {}

void ChannelRequestEvent::Execute() {
	// checking if there is available channel
	Client* client = network_->get_first_from_buffer();
	if (client != nullptr){
	bool is_added = network_->AddToBandwidth(client);
	// if there is then remove client from buffer and plan end of service event for him
		if (is_added) {
			spdlog::info("Time: " + std::to_string(network_->clock_) + " ##### U" + std::to_string(client->get_group()) + " is added to channel from buffer\n");
			network_->BufferPop();
			float event_t = client->get_service_time() + network_->clock_;
			Event* service_event;
			service_event = new UserEndOfServiceEvent(event_t, network_, client); 
			event_list_->insert(service_event);
			network_->BandwidthPrint();
			network_->BufferPrint();
		}
	}
	// ether way plan next channel request event
	float event_t = kRequestFrequency_ + network_->clock_;
	Event* next_request_event = new ChannelRequestEvent(event_t, network_, event_list_);
	event_list_->insert(next_request_event);
}