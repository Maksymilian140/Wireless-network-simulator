#include "channel_request_event.h"
#include "user_end_of_service_event.h"

ChannelRequestEvent::ChannelRequestEvent(int event_time, Network* network, EventList* event_list):Event(event_time, network), event_list_(event_list) {}

void ChannelRequestEvent::Execute() {
	// checking if there is available channel
	Client* client = network_->GetFirstFromBuffer();
	if (client != nullptr){
	bool is_added = network_->AddToBandwidth(client);
	// if there is then remove client from buffer and plan end of service event for him
		if (is_added) {
			spdlog::debug("Time: " + network_->GetClock() + "ms" + " ##### U" + std::to_string(client->GetGroup()) + " is added to channel from buffer\n");
			network_->BufferPop();
			int event_t = client->GetServiceTime() + network_->clock_;
			Event* service_event;
			service_event = new UserEndOfServiceEvent(event_t, network_, client); 
			event_list_->insert(service_event);
			network_->BandwidthPrint();
			network_->BufferPrint();
		}
	}
	// ether way plan next channel request event
	int event_t = kRequestFrequency_ + network_->clock_;
	Event* next_request_event = new ChannelRequestEvent(event_t, network_, event_list_);
	event_list_->insert(next_request_event);
}